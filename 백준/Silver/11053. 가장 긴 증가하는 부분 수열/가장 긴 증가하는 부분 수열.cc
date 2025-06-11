#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	int ans = 0;
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(dp[i], ans);
	}

	cout << ans << "\n";

	return 0;
}