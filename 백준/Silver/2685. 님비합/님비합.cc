#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int nimsum(int b, int x, int y)
{
    if (x < y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }

    vector<int> tmp1, tmp2;
    while (true)
    {
        tmp1.push_back(x % b);
        x /= b;

        if (x < b)
        {
            tmp1.push_back(x);
            break;
        }
    }

    while (true)
    {
        tmp2.push_back(y % b);
        y /= b;

        if (y < b)
        {
            tmp2.push_back(y);
            break;
        }
    }

    for (int i = 0; i < tmp2.size(); i++)
    {
        tmp1[i] += tmp2[i];
        tmp1[i] %= b;
    }

    int ret = 0;
    for (int i = 0; i < tmp1.size(); i++)
    {
        ret += tmp1[i] * pow(b, i);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int b, x, y, ans;
        cin >> b >> x >> y;
        ans = nimsum(b, x, y);
        cout << ans << "\n";
    }

    return 0;
}
