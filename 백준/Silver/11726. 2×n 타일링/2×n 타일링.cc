#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; cin >> N;

	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}

	cout << dp[N] << "\n";
	

	return 0;
}