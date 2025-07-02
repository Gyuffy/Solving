#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int m, f;
        cin >> m >> f;

        if (m == 0 && f == 0)
        {
            break;
        }

        cout << m + f << '\n';
    }

    return 0;
}
