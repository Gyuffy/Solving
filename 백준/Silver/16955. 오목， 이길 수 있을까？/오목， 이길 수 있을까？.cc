#include <iostream>
#include <string>
using namespace std;

char board[10][10];
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };

bool chkWin(int r, int c)
{
	for (int i = 0; i < 8; i++)
	{
		int cnt = 0;
		int dot = 0;
		for (int j = 1; j <= 4; j++)
		{
			int ny = r + j * dy[i];
			int nx = c + j * dx[i];
			if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
				continue;
			if (board[ny][nx] == 'O')
				continue;

			if(board[ny][nx] == 'X')
				cnt++;
			if (board[ny][nx] == '.')
				dot++;
		}
		if (cnt == 3 && dot == 1)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 10; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = row[j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 'X')
			{
				if (chkWin(i, j))
				{
					cout << "1\n";
					return 0;
				}
			}
		}
	}

	cout << "0\n";

	return 0;
}