#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

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

int N;
int MAP[51][51];
int dist[51][51];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void initDist()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dist[i][j] = 21e8;
		}
	}
}

void init()
{
	char temp[51];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			MAP[i][j] = temp[j] - '0';
		}
	}

	initDist();
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

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			
			int nextCost = MAP[ny][nx] ? cur.cost : cur.cost + 1;

			if (nextCost < dist[ny][nx])
			{
				dist[ny][nx] = nextCost;
				pq.push({ ny, nx, nextCost });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);
	init();
	dijkstra(0, 0);
	cout << dist[N - 1][N - 1] << "\n";

	return 0;
}