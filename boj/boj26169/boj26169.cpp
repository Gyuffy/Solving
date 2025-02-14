// 백준 26169 세 번 이내에 사과를 먹자
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Point
{
	int y, x;
}pt;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int pass;
int board[5][5];

void func(int lev, int cy, int cx, int cnt)
{
	// 종료 조건 1
	if (lev == 4)
	{
		return;
	}

	// 종료 조건 2
	if (cnt >= 2)
	{
		pass = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (board[ny][nx] == -1 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5 )
		{
			continue;
		}

		int val = board[ny][nx];

		board[ny][nx] = -1;

		func(lev + 1, ny, nx, cnt + val);

		board[ny][nx] = val;


	}
}

int main()
{
	// 입출력 버퍼 설정
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	// txt 파일로 입력 받아오기
	freopen("input.txt", "r", stdin);

	// init
	pass = 0;

	// 입력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
		}
	}

	cin >> pt.y >> pt.x;

	board[pt.y][pt.x] = -1;

	// BACKTRACKING
	func(0, pt.y, pt.x, 0);

	// 출력
	cout << pass;

	return 0;
}