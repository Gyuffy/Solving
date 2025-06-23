#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string a, b;
    cin >> n >> a >> b;

    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            diff++;
        }
    }

    cout << diff << '\n';

    return 0;
}
