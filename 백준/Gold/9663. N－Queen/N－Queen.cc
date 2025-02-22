#include <iostream>
using namespace std;

int N, cnt = 0;
int board[15] = {
	-1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1
};

bool canAttack(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[row] == board[i] || row - i == abs(board[row] - board[i]))
		{
			return true;
		}
	}

	return false;
}

void chess(int row)
{
	if (row == N)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		board[row] = i;
		if (canAttack(row, i))
		{
			continue;
		}
		chess(row + 1);
		board[row] = -1;
	}

}

int main()
{
	cin >> N;
	chess(0);
	cout << cnt;

	return 0;
}