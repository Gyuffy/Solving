#include <iostream>

using namespace std;

int N;
int square[500][500];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	if (N % 2 == 1)
	{
		for (int i = 0; i < N / 2; i++)
		{
			if (i < 3)
				square[0][i] = 2 * i + 1;
			else
				square[0][i] = 2 * (i + 1) + 1;
		}
		
		square[0][N / 2] = 7;

		for (int i = N / 2 + 1; i < N - 1; i++)
		{
			if (i - (N / 2) < 4)
				square[0][i] = 2 * (i - (N / 2));
			else
				square[0][i] = 2 * (i - (N / 2) + 1);
		}

		square[0][N - 1] = 8;
	}
	else
	{
		for (int i = 0; i < N / 2 - 1; i++)
		{
			if (i < 3)
				square[0][i] = 2 * i + 1;
			else
				square[0][i] = 2 * (i + 1) + 1;
		}

		square[0][N / 2 - 1] = 7;

		for (int i = N / 2; i < N - 1; i++)
		{
			if (i - (N / 2 - 1) < 4)
				square[0][i] = 2 * (i - (N / 2 - 1));
			else
				square[0][i] = 2 * (i - (N / 2 - 1) + 1);
		}

		square[0][N - 1] = 8;
	}

	for (int i = 1; i < N; i++)
	{
		square[i][0] = square[i - 1][N - 1];
		for (int j = 0; j < N - 1; j++)
		{
			square[i][j + 1] = square[i - 1][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << square[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}