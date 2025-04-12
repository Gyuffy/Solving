#include <iostream>
#include <queue>
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

int N, K;
int dist[100001];
int cost[] = { 1, 1, 0 };

void dijkstra(int st)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st, 0 });
	dist[st] = 0;
	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < 3; i++)
		{
			int next_cost = now.cost + cost[i];

			int tar;
			if (i == 0) tar = now.num + 1;
			else if (i == 1) tar = now.num - 1;
			else if (i == 2) tar = now.num * 2;

			if (tar <= 100000 && tar >= 0 && next_cost < dist[tar])
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
	cin.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < 100001; i++)
	{
		dist[i] = 21e8;
	}

	dijkstra(N);

	cout << dist[K] << '\n';

	return 0;
}