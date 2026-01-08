#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> MAP(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	vector<vector<long long>> DP(N, vector<long long>(N));
	DP[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (DP[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;

			int bottom = MAP[i][j] + i;
			int right = MAP[i][j] + j;

			if (bottom < N)
			{
				DP[bottom][j] = DP[bottom][j] + DP[i][j];
			}
			if (right < N)
			{
				DP[i][right] = DP[i][right] + DP[i][j];
			}
		}
	}

	cout << DP[N - 1][N - 1] << "\n";

	return 0;
}