#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, ans;
int MAP[20][20];
int DAT[101];

// 방향 벡터 : 좌하, 우하, 우상, 좌상
int dy[] = { 1, 1, -1, -1 };
int dx[] = { -1, 1, 1, -1 };

struct Point
{
	int y, x;
};

void init()
{
	ans = 0;
	memset(DAT, 0, sizeof(DAT));
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void dfs(Point st, Point cur, int dir, int cnt)
{
	// 종료 조건 1 : Start 지점으로 회귀한 경우
	if (st.y == cur.y && st.x == cur.x && cnt > 0)
	{
		ans = max(ans, cnt);
		return;
	}

	// PATH : 코너 돌기 or 안 돌기
	for (int i = 0; i < 2; i++)
	{
		dir += i;
		if (dir > 3)
			continue;

		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		int next_dessert = MAP[ny][nx];
		if (DAT[next_dessert] >= 1)
			continue;

		DAT[next_dessert]++;
		cnt++;
		dfs(st, { ny, nx }, dir, cnt);
		cnt--;
		DAT[next_dessert]--;
		dir -= i;
	}
}

void solve()
{
	Point start_pt;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			start_pt = { i, j };
			dfs(start_pt, start_pt, 0, 0);
			memset(DAT, 0, sizeof(DAT));
		}
	}
	if (ans == 0)
		ans = -1;
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
		solve();
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}