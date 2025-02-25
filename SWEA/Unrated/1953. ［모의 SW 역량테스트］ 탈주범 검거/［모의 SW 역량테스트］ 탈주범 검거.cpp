#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M, R, C, L, ans;
int MAP[50][50];

// 방향벡터 상, 하, 좌, 우
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

// BFS 방문 좌표 + 거리 계산
int dist[50][50];

struct Point
{
	int y;
	int x;
};

void init()
{
	// 테스트 케이스마다 초기화
	memset(dist, 0, sizeof(dist));
	ans = 0;
}

void input()
{
	cin >> N >> M >> R >> C >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

bool chkNext(int dir, int ny, int nx)
{
	int next = MAP[ny][nx];

	if (next == 0)
		return false;
	else if (next == 1)
	{
		if (dir < 4)
			return true;
	}
	else if (next == 2)
	{
		if (dir < 2)
			return true;
	}
	else if (next == 3)
	{
		if (dir == 2 || dir == 3)
			return true;
	}
	else if (next == 4)
	{
		if (dir == 1 || dir == 2)
			return true;
	}
	else if (next == 5)
	{
		if (dir == 0 || dir == 2)
			return true;
	}
	else if (next == 6)
	{
		if (dir == 0 || dir == 3)
			return true;
	}
	else if (next == 7)
	{
		if (dir == 1 || dir == 3)
			return true;
	}
	return false;
}

void bfs(Point st)
{
	queue<Point> q;
	q.push(st);
	dist[st.y][st.x] = 1;
	
	while (!q.empty())
	{
		// 현재 좌표
		Point cur = q.front();
		q.pop();
		
		// 현재 터널의 정보
		int now = MAP[cur.y][cur.x];
		
		// 탈주범 존재 구역 카운트
		if (dist[cur.y][cur.x] <= L)
			ans++;

		if (now == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (dist[ny][nx] >= 1)
					continue;
				if (!chkNext(i, ny, nx))
					continue;
				dist[ny][nx] = dist[cur.y][cur.x] + 1;
				q.push({ ny, nx });
			}
		}
		else if (now == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (dist[ny][nx] >= 1)
					continue;
				if (!chkNext(i, ny, nx))
					continue;
				dist[ny][nx] = dist[cur.y][cur.x] + 1;
				q.push({ ny, nx });
			}
		}
		else if (now == 3)
		{
			for (int i = 2; i < 4; i++)
			{
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (dist[ny][nx] >= 1)
					continue;
				if (!chkNext(i, ny, nx))
					continue;
				dist[ny][nx] = dist[cur.y][cur.x] + 1;
				q.push({ ny, nx });
			}
		}
		else if (now == 4)
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					int ny = cur.y + dy[0];
					int nx = cur.x + dx[0];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(0, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
				else if (i == 1)
				{
					int ny = cur.y + dy[3];
					int nx = cur.x + dx[3];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(3, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
			}
		}
		else if (now == 5)
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					int ny = cur.y + dy[1];
					int nx = cur.x + dx[1];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(1, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
				else if (i == 1)
				{
					int ny = cur.y + dy[3];
					int nx = cur.x + dx[3];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(3, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
			}
		}
		else if (now == 6)
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					int ny = cur.y + dy[1];
					int nx = cur.x + dx[1];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(1, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
				else if (i == 1)
				{
					int ny = cur.y + dy[2];
					int nx = cur.x + dx[2];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(2, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
			}
		}
		else if (now == 7)
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					int ny = cur.y + dy[0];
					int nx = cur.x + dx[0];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(0, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
				else if (i == 1)
				{
					int ny = cur.y + dy[2];
					int nx = cur.x + dx[2];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue;
					if (dist[ny][nx] >= 1)
						continue;
					if (!chkNext(2, ny, nx))
						continue;
					dist[ny][nx] = dist[cur.y][cur.x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	
	int T, test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		bfs({ R, C });
		cout << "#" << test_case << " " << ans << "\n";
	}


	return 0;
}