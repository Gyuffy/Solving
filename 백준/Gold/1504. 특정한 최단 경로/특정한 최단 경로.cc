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

int N, E;
vector<Edge> v[801];
int dist[801];

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
			int next_cost = now.cost + v[now.num][i].cost;

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
	cin.tie(nullptr);

	int a, b, c;
	int v1, v2;
	int ans = 0;
	int path1 = 0, path2 = 0;

	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	cin >> v1 >> v2;

	for (int i = 0; i < 801; i++)
	{
		dist[i] = 21e8;
	}
	dijkstra(1);

	path1 += dist[v1];
	path2 += dist[v2];

	if (path1 >= 21e8 && path2 >= 21e8)
	{
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < 801; i++)
	{
		dist[i] = 21e8;
	}
	dijkstra(v1);

	path1 += dist[v2];

	for (int i = 0; i < 801; i++)
	{
		dist[i] = 21e8;
	}
	dijkstra(v2);

	path2 += dist[v1];
	path1 += dist[N];

	for (int i = 0; i < 801; i++)
	{
		dist[i] = 21e8;
	}
	dijkstra(v1);

	path2 += dist[N];

	ans = path1 < path2 ? path1 : path2;

	if (ans >= 21e8 || E == 0 || ans < 0)
		ans = -1;

	cout << ans << "\n";

	return 0;
}