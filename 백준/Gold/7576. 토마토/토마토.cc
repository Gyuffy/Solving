#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int y;
	int x;
};

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int N, M, ans, num, cnt;
int box[1000][1000];

queue<Point> q;
int dist[1000][1000];

void init()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push({ i, j });
			}
			if (box[i][j] == 0)
			{
				num++;
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

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (box[ny][nx] != 0)
				continue;
			
			dist[ny][nx] = dist[cur.y][cur.x] + 1;
			box[ny][nx] = 1;
			ans = ans > dist[ny][nx] ? ans : dist[ny][nx];
			cnt++;
			
			q.push({ ny, nx });
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