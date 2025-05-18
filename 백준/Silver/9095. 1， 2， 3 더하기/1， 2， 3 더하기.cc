#include <iostream>
using namespace std;

void solve()
{
	int n;
	int dp[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> n;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cout << dp[n] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		solve();
	}

	return 0;
}