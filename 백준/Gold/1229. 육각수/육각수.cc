#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    vector<int> hexa;
    for (long long n = 1;; ++n)
    {
        long long h = n * (2 * n - 1);
        if (h > N)
        {
            break;
        }
        hexa.push_back(static_cast<int>(h));
    }

    const int INF = 7;
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int x = 1; x <= N; ++x)
    {
        for (int h : hexa)
        {
            if (h > x)
            {
                break;
            }
            dp[x] = min(dp[x], dp[x - h] + 1);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}
