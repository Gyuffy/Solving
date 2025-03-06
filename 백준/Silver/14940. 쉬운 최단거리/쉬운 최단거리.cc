#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int MAP[1000][1000];
int dist[1000][1000];

int ty, tx;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

struct Point
{
	int y, x;
};

void bfs(int sy, int sx)
{
	queue<Point> q;
	q.push({ sy, sx });
	dist[sy][sx] = 0;

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (dist[ny][nx] > 0)
				continue;
			if (MAP[ny][nx] != -1)
				continue;

			dist[ny][nx] = dist[cur.y][cur.x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 2)
			{
				ty = i;
				tx = j;
			}
			if (MAP[i][j] == 1)
			{
				MAP[i][j] *= -1;
				dist[i][j] = MAP[i][j];
			}
		}
	}

	bfs(ty, tx);


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;
}