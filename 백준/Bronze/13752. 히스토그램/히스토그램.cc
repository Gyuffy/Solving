#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }
    while (T--)
    {
        int n;
        cin >> n;
        cout << string(n, '=') << '\n';
    }
    return 0;
}
