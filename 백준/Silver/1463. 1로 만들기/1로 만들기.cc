#include <iostream>
using namespace std;

int N;
int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	dp[0] = 21e8;
	dp[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		dp[i] = i % 2 != 0 ? dp[i] :
			dp[i] < dp[i / 2] + 1 ? dp[i] : dp[i / 2] + 1;
		dp[i] = i % 3 != 0 ? dp[i] :
			dp[i] < dp[i / 3] + 1 ? dp[i] : dp[i / 3] + 1;
	}

	cout << dp[N] << '\n';

	return 0;
}