// 민코딩 장기 포 게임
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, cnt;
int board[50][50];
int origin[50][50];
int visited[50][50];

struct Cannon
{
	int y, x;
}cannon;

void init()
{
	cnt = 0;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				cannon.y = i;
				cannon.x = j;
				board[i][j] = 0;
			}
			origin[i][j] = board[i][j];
		}
	}
}

bool cannot_go(int tg_y, int tg_x, int pt_y, int pt_x)
{
	if (tg_y == 0 && tg_x == 1 && pt_y == 0 && pt_x == 4)
	{
		int de = 1;
	}

	// 타겟 위치와 포의 위치가 같은 경우
	if (tg_y == pt_y && tg_x == pt_x)
	{
		return true;
	}

	// 타겟 위치가 포의 대각 방향에 있는 경우
	if (tg_y != pt_y && tg_x != pt_x)
	{
		return true;
	}

	// 타겟 위치가 포의 윗 방향에 있는 경우
	if (tg_x == pt_x && tg_y < pt_y)
	{
		int is_pawn = 0;
		for (int i = pt_y - 1; i >= tg_y; i--)
		{
			if (is_pawn == 1 && i == tg_y)
			{
				// 타겟 위치까지 졸의 개수가 1개였다면 false 반환
				return false;
			}
			if (is_pawn == 0 && i == tg_y)
			{
				// 타겟 위치까지 만난 졸이 1개도 없다면 true 반환
				return true;
			}
			if (is_pawn > 1)
			{
				// 타겟 위치까지 졸의 개수가 1개를 초과하면 true 반환
				return true;
			}
			if (board[i][pt_x] == 1)
			{
				// 졸을 만날 때마다 졸의 개수 +1
				is_pawn++;
			}
		}
	}

	// 타겟이 포의 아래 방향에 있는 경우
	if (tg_x == pt_x && tg_y > pt_y)
	{
		int is_pawn = 0;
		for (int i = pt_y + 1; i <= tg_y; i++)
		{
			if (is_pawn == 1 && i == tg_y)
			{
				return false;
			}
			if (is_pawn == 0 && i == tg_y)
			{
				return true;
			}
			if (is_pawn > 1)
			{
				return true;
			}
			if (board[i][pt_x] == 1)
			{
				is_pawn++;
			}
		}
	}

	// 타겟이 포의 왼쪽 방향에 있는 경우
	if (tg_y == pt_y && tg_x < pt_x)
	{
		int is_pawn = 0;
		for (int i = pt_x - 1; i >= tg_x; i--)
		{
			if (is_pawn == 1 && i == tg_x)
			{
				return false;
			}
			if (is_pawn == 0 && i == tg_x)
			{
				return true;
			}
			if (is_pawn > 1)
			{
				return true;
			}
			if (board[pt_y][i] == 1)
			{
				is_pawn++;
			}
		}
	}

	// 타겟이 포의 오른쪽 방향에 있는 경우
	if (tg_y == pt_y && tg_x > pt_x)
	{
		int is_pawn = 0;
		for (int i = pt_x + 1; i <= tg_x; i++)
		{
			if (is_pawn == 1 && i == tg_x)
			{
				return false;
			}
			if (is_pawn == 0 && i == tg_x)
			{
				return true;
			}
			if (is_pawn > 1)
			{
				return true;
			}
			if (board[pt_y][i] == 1)
			{
				is_pawn++;
			}
		}
	}
}

void move(int lev, int cy, int cx)
{
	if (lev == 3)
	{
		return;
	}
	if (cy == 0 && cx == 4)
	{
		int de = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cy == 0 && cx == 4 && i == 2)
			{
				int de = 1;
			}

			if (board[i][j] == -1)
			{
				continue;
			}

			if (cannot_go(i, j, cy, cx))
			{
				// (i, j)로 못가면 continue
				continue;
			}
			else
			{
				// 갈 수 있으면 move 후 (i, j)에서 반복
				if (board[i][j] == 1 && visited[i][j] == 0)
				{
					cnt++;
					board[i][j] = -1;
					visited[i][j] = 1;
				}
				move(lev + 1, i, j);

				board[i][j] = origin[i][j];
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
		move(0, cannon.y, cannon.x);
		cout << "#" << tc << " " << cnt << "\n";
	}

}