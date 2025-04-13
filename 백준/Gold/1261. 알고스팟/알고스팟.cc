#include <iostream>
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

int N, M;
int MAP[100][100];
int dist[100][100];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void dijkstra(int sy, int sx)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ sy, sx, 0 });
	dist[sy][sx] = 0;
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

			if (ny >= N || ny < 0 || nx >= M || nx < 0)
				continue;

			int next_cost = now.cost + MAP[ny][nx];
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

	cin >> M >> N;

	char input_row[101];
	for (int i = 0; i < N; i++)
	{
		cin >> input_row;
		for (int j = 0; j < M; j++)
		{
			MAP[i][j] = input_row[j] - '0';
			dist[i][j] = 21e8;
		}
	}

	dijkstra(0, 0);

	cout << dist[N - 1][M - 1] << "\n";

	return 0;
}