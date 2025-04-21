#define MAX_ROW 2000
#define MAX_COL 2000
#include <iostream>
using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

char board[MAX_ROW][MAX_COL];
int ansTable[MAX_ROW][MAX_COL];

int N, M;
int cntB = 0;

void printAnswer()
{
	cout << "1\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << ansTable[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char row[MAX_COL + 1];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> row;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = row[j];
			if (board[i][j] == 'B')
				cntB++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ansTable[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny >= N || ny < 0 || nx >= M || nx < 0)
					continue;
				if (board[ny][nx] == 'W')
				{
					board[ny][nx] = 'B';
					cntB++;
				}
				else if (board[ny][nx] == 'B')
				{
					board[ny][nx] = 'W';
					cntB--;
				}
			}
			ansTable[i][j] = 2;
			if (cntB == 0)
			{
				printAnswer();
				return 0;
			}
		}
	}

	cout << "1\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'B')
			{
				cout << "3";
			}
			else
			{
				cout << "2";
			}
		}
		cout << "\n";
	}

	return 0;
}