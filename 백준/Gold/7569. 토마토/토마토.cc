#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int z, y, x;
};

int N, M, H, ans, cnt, num;
int box[100][100][100];

queue<Point> q;

int dist[100][100][100];
int dz[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0, 0, 0 };
int dx[] = { 0, 0, -1, 1, 0, 0 };

void init()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					q.push({ i, j, k });
				}
				if (box[i][j][k] == 0)
				{
					num++;
				}
			}
		}
	}
}

void bfs()
{
	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nz = cur.z + dz[i];
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (nz < 0 || nz >= H
				|| ny < 0 || ny >= N
				|| nx < 0 || nx >= M)
				continue;
			if (box[nz][ny][nx] != 0)
				continue;
			if (dist[nz][ny][nx] > 0)
				continue;

			box[nz][ny][nx] = 1;
			dist[nz][ny][nx] = dist[cur.z][cur.y][cur.x] + 1;
			ans = ans > dist[nz][ny][nx] ? ans : dist[nz][ny][nx];
			cnt++;
			q.push({ nz, ny, nx });
		}
	}

	ans = cnt == num ? ans : -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	init();
	bfs();
	cout << ans << "\n";

	return 0;
}