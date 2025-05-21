#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int T; cin >> T;

	int dp[41][2];

	for (int tc = 0; tc < T; tc++)
	{
		int N;
		cin >> N;

		dp[0][0] = 1;
		dp[0][1] = 0;
		dp[1][0] = 0;
		dp[1][1] = 1;
		dp[2][0] = 1;
		dp[2][1] = 1;

		for (int i = 3; i <= N; i++)
		{
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		}

		cout << dp[N][0] << " " << dp[N][1] << "\n";
	}
	

	return 0;
}