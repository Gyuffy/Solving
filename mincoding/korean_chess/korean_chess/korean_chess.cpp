// 민코딩 장기 포 게임
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int N, cnt, ans;
int board[50][50];
int origin_board[50][50];
int can_area[50][50];

int visited[50][50];
int move_dir[4] = { -1,-1,-1,-1 };

struct Point
{
	int y, x;
};

Point cannon;
//Point soldiers[2499];

void init()
{
	cnt = 0;
	ans = 0;
	memset(visited, 0, sizeof(visited));
}

void input()
{
	cin >> N;
	int soldier_idx = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			origin_board[i][j] = board[i][j];
			/*if (board[i][j] == 1)
			{
				soldiers[soldier_idx].y = i;
				soldiers[soldier_idx].x = j;
				soldier_idx++;
			}*/
			if (board[i][j] == 2)
			{
				origin_board[i][j] = 0;
				cannon.y = i;
				cannon.x = j;
			}
		}
	}
}

void make_can_area(int cy, int cx)
{
	memset(can_area, 0, sizeof(can_area));
	int is_soldier = 0;
	for (int i = cy -1; i >= 0; i--)
	{
		if (is_soldier == 0 && board[i][cx] == 1)
		{
			is_soldier = 1;
			can_area[i][cx] = 0;
		}
		else if (is_soldier == 1 && board[i][cx] == 0)
		{
			can_area[i][cx] = 1;
		}
		else if (is_soldier == 1 && board[i][cx] == 1)
		{
			can_area[i][cx] = 1;
			is_soldier = 2;
		}
		else
		{
			can_area[i][cx] = 0;
		}
	}

	is_soldier = 0;
	for (int i = cy + 1; i < N; i++)
	{
		if (is_soldier == 0 && board[i][cx] == 1)
		{
			is_soldier = 1;
			can_area[i][cx] = 0;
		}
		else if (is_soldier == 1 && board[i][cx] == 0)
		{
			can_area[i][cx] = 1;
		}
		else if (is_soldier == 1 && board[i][cx] == 1)
		{
			can_area[i][cx] = 1;
			is_soldier = 2;
		}
		else
		{
			can_area[i][cx] = 0;
		}
	}

	is_soldier = 0;
	for (int i = cx - 1; i >= 0; i--)
	{
		if (is_soldier == 0 && board[cy][i] == 1)
		{
			is_soldier = 1;
			can_area[cy][i] = 0;
		}
		else if (is_soldier == 1 && board[cy][i] == 0)
		{
			can_area[cy][i] = 1;
		}
		else if (is_soldier == 1 && board[cy][i] == 1)
		{
			can_area[cy][i] = 1;
			is_soldier = 2;
		}
		else
		{
			can_area[cy][i] = 0;
		}
	}

	is_soldier = 0;
	for (int i = cx + 1; i < N; i++)
	{
		if (is_soldier == 0 && board[cy][i] == 1)
		{
			is_soldier = 1;
			can_area[cy][i] = 0;
		}
		else if (is_soldier == 1 && board[cy][i] == 0)
		{
			can_area[cy][i] = 1;
		}
		else if (is_soldier == 1 && board[cy][i] == 1)
		{
			can_area[cy][i] = 1;
			is_soldier = 2;
		}
		else
		{
			can_area[cy][i] = 0;
		}
	}
}

void move_cannon(int lev, int cy, int cx)
{
	if (lev == 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = origin_board[i][j];
			}
		}
		return;
	}

	make_can_area(cy, cx);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (can_area[i][j] == 0)
			{
				continue;
			}
			else
			{
				if (board[i][j] == 1)
				{
					board[i][j] = 0;
					if (visited[i][j] == 0)
					{
						cnt++;
						visited[i][j] = 1;
						cout << "y : " << i << " " << "x : " << j << "\n";
					}
				}
				move_cannon(lev + 1, i, j);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		init();
		input();
		board[cannon.y][cannon.x] = 0;
		move_cannon(0, cannon.y, cannon.x);
		cout << "#" << tc << " " << cnt << "\n";
	}


	return 0;
}