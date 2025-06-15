#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n1, n2, n12;
    if (!(cin >> n1 >> n2 >> n12))
    {
        return 0;
    }

    long long estimate = ((n1 + 1) * (n2 + 1)) / (n12 + 1) - 1;
    cout << estimate << '\n';

    return 0;
}
