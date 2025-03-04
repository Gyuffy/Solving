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

int V, E, K, ans;
int dist[20001];
vector<Edge> v[20001];

void init()
{
	// 정점의 개수와 간선의 개수 입력
	cin >> V >> E;

	// 시작 정점의 번호 입력
	cin >> K;

	// 간선의 정보 입력
	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}

	// Dijkstra 초기화
	for (int i = 1; i <= V; i++)
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
		Edge cur = pq.top();
		pq.pop();

		if (dist[cur.num] < cur.cost)
			continue;
		
		for (int i = 0; i < v[cur.num].size(); i++)
		{
			int next_cost = cur.cost + v[cur.num][i].cost;
			int tar = v[cur.num][i].num;

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
	dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		ans = dist[i];
		if (ans == 21e8)
			cout << "INF\n";
		else
			cout << ans << "\n";
	}

	return 0;
}