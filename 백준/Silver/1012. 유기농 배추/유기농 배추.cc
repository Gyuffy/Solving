#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

struct Point
{
	int y;
	int x;
}pos[2500];

int M, N, K, ans;
int MAP[50][50];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void init() 
{
	ans = 1;
	memset(MAP, 0, sizeof(MAP));
}

void input()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> pos[i].x >> pos[i].y;
		MAP[pos[i].y][pos[i].x] = -1;
	}
}

void recur(Point st)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = st.y + dy[i];
		int nx = st.x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (MAP[ny][nx] != -1)
			continue;

		MAP[ny][nx] = ans;
		recur({ ny, nx });
	}

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
		for (int i = 0; i < K; i++)
		{
			if (MAP[pos[i].y][pos[i].x] != -1)
				continue;
			recur(pos[i]);
			ans++;
		}
		cout << ans - 1 << "\n";
	}

	return 0;
}