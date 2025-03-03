#define _CRT_SECURE_NO_WARNINGS
#define CALI 301
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Cell
{
	int y;
	int x;
	int t;	// 생명력 수치 t
	int s;	// 세포의 상태 s ( 0: 죽음, 1: 활성. 2: 비활성)
};

struct Point
{
	int y;
	int x;
};

int N, M, K, ans;
int MAP[700][700];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int dist[700][700];

struct cmp
{
	bool operator()(Cell a, Cell b)
	{
		return MAP[a.y][a.x] < MAP[b.y][b.x];
	}
};

priority_queue<Cell, vector<Cell>, cmp> pq;
vector<Cell> v;

void init()
{
	memset(dist, 0, sizeof(dist));
	memset(MAP, 0, sizeof(MAP));

	v.clear();
}

void input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i + CALI][j + CALI];
			if (MAP[i + CALI][j + CALI] != 0)
				v.push_back({ i + CALI, j + CALI, MAP[i + CALI][j + CALI], 2 });
		}
	}
}

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

			if (MAP[ny][nx] != 0)
				continue;

			int nextDist = dist[cur.y][cur.x] + 1;
			if (nextDist > 1)
				continue;

			dist[ny][nx] = nextDist;
			MAP[ny][nx] = MAP[sy][sx];
			v.push_back({ ny, nx, MAP[sy][sx], 2 });
			q.push({ ny, nx });
		}
	}
}

void solve()
{
	while (K--)
	{
		vector<int> deadCell;
		// 생존 세포 순회
		for (int i = 0; i < v.size(); i++)
		{
			Cell now = v[i];

			// 비활성 상태
			if (now.s == 2)
			{
				now.t--;
				if (now.t == 0)
				{
					now.s--;
					now.t = MAP[now.y][now.x];
				}
			}

			// 활성 상태
			else if (now.s == 1)
			{
				pq.push(now);
				now.t--;
				if (now.t == 0)
				{
					now.s--;
					// 죽은 세포 기록
					deadCell.push_back(i);
				}
			}

			v[i] = now;
		}

		// 순회가 끝나고 죽은 세포 벡터에서 제거
		for (int i = deadCell.size() - 1; i >= 0; i--)
		{
			v.erase(v.begin() + deadCell[i]);
		}

		// pq에 담은 세포의 번식
		while(!pq.empty())
		{
			Cell now = pq.top();
			pq.pop();
			
			bfs(now.y, now.x);
			//memset(dist, 0, sizeof(dist));
		}
	}

	ans = v.size();
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}