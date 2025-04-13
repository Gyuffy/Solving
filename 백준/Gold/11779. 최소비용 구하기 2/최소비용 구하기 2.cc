#include <iostream>
#include <vector>
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

int n, m, st, en;
vector<Edge> v[1001];
int dist[1001];
int route[1001];

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
				route[tar] = now.num;
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

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}
	cin >> st >> en;

	for (int i = 0; i < 1001; i++)
	{
		dist[i] = 21e8;
	}
	
	dijkstra(st);
	
	cout << dist[en] << "\n";

	int cnt = 0;
	int trace = en;

	vector<int> visit_city;

	while (++cnt)
	{
		if (route[trace] == 0)
		{
			visit_city.push_back(st);
			break;
		}
		visit_city.push_back(trace);
		trace = route[trace];
	}

	cout << cnt << "\n";

	for (int i = visit_city.size() - 1; i >= 0; i--)
	{
		cout << visit_city[i] << " ";
	}

	cout << "\n";

	return 0;
}