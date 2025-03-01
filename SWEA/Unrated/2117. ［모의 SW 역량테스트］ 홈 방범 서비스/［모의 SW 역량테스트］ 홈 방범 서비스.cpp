#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int y, x;
};

int N, M;
int homeCnt, ans;

int MAP[20][20];
int dist[20][20];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void init()
{
	homeCnt = 0;
	ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dist[i][j] = 0;
		}
	}
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void bfs(int sy, int sx, int K)
{
	queue<Point> q;
	q.push({ sy, sx });
	dist[sy][sx] = 1;
	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		// 현재 좌표가 집이면 cnt를 1씩 증가
		if (MAP[cur.y][cur.x] == 1)
		{
			homeCnt++;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			// 범위 밖과 이미 방문했던 인접노드는 고려하지 않는다.
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (dist[ny][nx] > 0)
				continue;
			
			int nextDist = dist[cur.y][cur.x] + 1;

			// 서비스 영역 바깥의 좌표는 고려하지 않는다.
			if (nextDist > K)
				continue;

			dist[ny][nx] = nextDist;
			q.push({ ny, nx });
		}
	}
}

void solve()
{
	int maxK = 1;
	for (int i = N + 1; i >= maxK; i--)
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				bfs(r, c, i);

				// 보안회사의 이익 계산
				int cost = (i * i) + ((i - 1) * (i - 1));
				int profit = (homeCnt * M) - cost;
				// 손해를 보지 않는다면, 집의 개수를 게산
				// 서비스 영역은 고정
				if (profit >= 0)
				{
					maxK = i;
					if (homeCnt > ans)
					{
						ans = homeCnt;
					}
				}

				// BFS를 끝낼 때마다 dist 배열 초기화
				for (int u = 0; u < N; u++)
				{
					for (int v = 0; v < N; v++)
					{
						dist[u][v] = 0;
					}
				}

				homeCnt = 0;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);
	int T, test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		solve();
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}