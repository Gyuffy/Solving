#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

int N, M, P, maxVal;
int dist[1001];
int sum[1001];
vector<Edge> v[1001];

void init()
{
	maxVal = 0;

	cin >> N >> M >> P;
	int from, to, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}

	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}
}

void dijkstra(int st)
{
	priority_queue<Edge, vector<Edge>, compare> pq;
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
			int nextCost = now.cost + v[now.num][i].cost;
			int tar = v[now.num][i].num;

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
	// freopen("sample_input.txt", "r", stdin);
	init();
	for (int i = 1; i <= N; i++)
	{
		dijkstra(i);
		sum[i] += dist[P];
		for (int i = 1; i <= N; i++)
		{
			dist[i] = 21e8;
		}
	}
	dijkstra(P);

	for (int i = 1; i <= N; i++)
	{
		sum[i] += dist[i];
		maxVal = max(maxVal, sum[i]);
	}

	cout << maxVal << "\n";

	return 0;
}