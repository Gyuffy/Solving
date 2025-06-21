#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double p;
    if (!(cin >> p))
    {
        return 0;
    }

    cout << fixed << setprecision(10);
    cout << 100.0 / p << '\n';
    cout << 100.0 / (100.0 - p) << '\n';

    return 0;
}
