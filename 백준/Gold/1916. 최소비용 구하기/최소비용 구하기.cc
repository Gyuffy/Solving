#define _CRT_SECURE_NO_WARNINGS
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

int N, M;
int st_city, en_city;
int dist[1001];
vector<Edge> v[1001];

void init()
{
	// 입력부
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}
	cin >> st_city >> en_city;

	// Dijkstra 초기화
	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}
}

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
	// freopen("sample_input.txt", "r", stdin);
	init();
	dijkstra(st_city);
	cout << dist[en_city] << "\n";

	return 0;
}