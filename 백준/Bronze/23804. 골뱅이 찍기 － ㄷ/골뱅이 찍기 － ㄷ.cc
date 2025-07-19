#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    string full(5 * N, '@');
    string left(N, '@');

    for (int i = 0; i < N; ++i)
        cout << full << '\n';

    for (int i = 0; i < 3 * N; ++i)
        cout << left << '\n';

    for (int i = 0; i < N; ++i)
        cout << full << '\n';

    return 0;
}
