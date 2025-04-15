#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge
{
	int num;
	int cost;
};

struct cmp
{
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

int n, m, r;
int items[101];
vector<Edge> v[101];
int dist[101];
int max_val = 0;

void dijkstra(int st)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost)
			continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int next_cost = dist[now.num] + v[now.num][i].cost;

			int tar = v[now.num][i].num;
			if (next_cost < dist[tar])
			{
				dist[tar] = next_cost;
				pq.push({ tar, next_cost });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}

	for (int i = 0; i < r; i++)
	{
		int to, from, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[j] = 21e8;
		}
		dijkstra(i);

		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[j] <= m)
			{
				sum += items[j];
			}
		}
		max_val = max_val > sum ? max_val : sum;
	}

	cout << max_val << "\n";

	return 0;
}