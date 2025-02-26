#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int y;
	int x;
	int cost;
};

struct compare
{
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

int N, A, B;
int maxCost;
char MAP[31][31];
int dist[31][31];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void init()
{
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	// 아래는 초기화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dist[i][j] = 21e8;
		}
	}

	maxCost = 0;
}

void dijkstra(int sy, int sx)
{
	priority_queue<Edge, vector<Edge>, compare> pq;
	pq.push({ sy, sx, 0 });
	dist[sy][sx] = 0;
	while (!pq.empty())
	{
		Edge cur = pq.top();
		pq.pop();

		if (dist[cur.y][cur.x] < cur.cost)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (cur.y == 1 && cur.x == 1 && ny == 1 && nx == 2 && sy == 1 && sx == 0)
			{
				int de = 1;
			}

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			int nextCost = (MAP[cur.y][cur.x] == MAP[ny][nx]) ? cur.cost + A : cur.cost + B;

			if (nextCost < dist[ny][nx])
			{
				//maxCost = max(maxCost, nextCost);
				dist[ny][nx] = nextCost;
				pq.push({ ny, nx, nextCost });
			}
		}
	}
}

int main()
{
	freopen("sample_input.txt", "r", stdin);
	init();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dijkstra(i, j);
			for (int r = 0; r < N; r++)
			{
				for (int c = 0; c < N; c++)
				{
					maxCost = max(maxCost, dist[r][c]);
				}
			}

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					dist[i][j] = 21e8;
				}
			}
		}
	}

	cout << maxCost << "\n";

	return 0;
}