#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge
{
	int num;
	int cost;
};

struct compare
{
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

int N, M;
int dist[1001];
vector<Edge> v[1001];

void initDist()
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}
}

void init()
{
	int from, to, cost;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		v[to].push_back({ from, cost });
	}
	initDist();
}

void dijkstra(int st)
{
	priority_queue<Edge, vector<Edge>, compare> pq;
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
			int nextCost = cur.cost + v[cur.num][i].cost;
			int tar = v[cur.num][i].num;

			if (nextCost < dist[tar])
			{
				dist[tar] = nextCost;
				pq.push({ tar, nextCost });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("sample_input.txt", "r", stdin);
	init();
	dijkstra(N);

	return 0;
}