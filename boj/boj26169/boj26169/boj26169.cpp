// 백준 26169번 세 번 이내에 사과를 먹자
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int ans = 0;
int max_count = 0;
int flag = 0;

int board[5][5];
int origin[5][5];

int ny;
int nx;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int path[3] = { -1, -1, -1 };

struct Point
{
	int y, x;
}pt;

void move(int lev, int py, int px, int cnt)
{
	if (lev == 3)
	{
		if (max_count < cnt)
		{
			max_count = cnt;
			if (cnt == 2)
			{
				int de = 1;
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		path[lev] = i;
		ny = py + dy[i];
		nx = px + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
			continue;
		if (board[ny][nx] == -1)
			continue;

		if (board[ny][nx] == 1)
		{
			cnt++;
		}
		board[ny][nx] = -1;
		move(lev + 1, ny, nx, cnt);
		if (origin[ny][nx] == 1)
			cnt--;
		board[ny][nx] = origin[ny][nx];
		path[lev] = -1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
			origin[i][j] = board[i][j];
		}
	}

	cin >> pt.y >> pt.x;

	/*if (board[pt.y][pt.x] == 1)
	{
		cnt++;
	}
	board[pt.y][pt.x] = -1;*/

	move(0, pt.y, pt.x, 0);

	ans = max_count >= 2 ? 1 : 0;
	cout << ans;
	
}