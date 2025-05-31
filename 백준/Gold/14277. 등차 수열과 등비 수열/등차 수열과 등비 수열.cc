#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d, u;
    cin >> a >> b >> c >> d >> u;

    long long cnt = 0;

    if (b == 0)
    {
        if (a <= u)
            cnt++;
    }
    else if (a <= u)
    {
        cnt += (u - a) / b + 1;
    }

    unordered_set<long long> visited;
    long long term = c;

    while (term <= u)
    {
        bool isInAP = false;
        if (b == 0)
        {
            isInAP = (term == a);
        }
        else if ((term - a) % b == 0 && (term - a) / b >= 0)
        {
            isInAP = true;
        }

        if (!isInAP)
        {
            cnt++;
        }

        if (d == 1)
            break;
        if (term > u / d)
            break;

        term *= d;
    }

    cout << cnt << '\n';
    return 0;
}
