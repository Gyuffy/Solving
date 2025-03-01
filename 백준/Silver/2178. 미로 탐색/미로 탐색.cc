#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int y, x;
};

int N, M;
int MAP[100][100];
int dist[100][100];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void bfs(int sy, int sx)
{
	queue<Point> q;
	q.push({ sy, sx });
	dist[sy][sx] = 1;

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
			if (MAP[ny][nx] == 0)
				continue;
			if (dist[ny][nx] > 0)
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

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		char ch[101];
		cin >> ch;
		for (int j = 0; j < M; j++)
		{
			int num = ch[j] - '0';
			MAP[i][j] = num;
		}
	}

	bfs(0, 0);
	cout << dist[N - 1][M - 1] << "\n";

	return 0;
}