#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n, k;
        if (!(cin >> n >> k))
        {
            return 0;
        }
        if (n == 0 && k == 0)
        {
            break;
        }

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }

        static long long dp[101][101];
        for (int i = 1; i <= n; ++i)
        {
            fill(dp[i], dp[i] + k + 1, 0LL);
            dp[i][1] = 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (a[j] < a[i])
                {
                    for (int len = 2; len <= k; ++len)
                    {
                        dp[i][len] += dp[j][len - 1];
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans += dp[i][k];
        }
        cout << ans << '\n';
    }
    return 0;
}
