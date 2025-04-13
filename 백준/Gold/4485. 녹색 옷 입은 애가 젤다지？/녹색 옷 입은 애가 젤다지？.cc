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

struct cmp
{
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

int N;
int MAP[125][125];
int dist[125][125];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			dist[i][j] = 21e8;
		}
	}
}

void dijkstra(int sy, int sx)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ sy, sx, MAP[sy][sx] });
	dist[sy][sx] = MAP[sy][sx];

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.y][now.x] < now.cost)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			int next_cost = dist[now.y][now.x] + MAP[ny][nx];
			if (next_cost < dist[ny][nx])
			{
				dist[ny][nx] = next_cost;
				pq.push({ ny, nx, next_cost });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc = 0;
	while (++tc)
	{
		cin >> N;
		if (N == 0) return 0;

		input();
		dijkstra(0, 0);
		cout << "Problem " << tc << ": " << dist[N - 1][N - 1] << "\n";
	}
	return 0;
}