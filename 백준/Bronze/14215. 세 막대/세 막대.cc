#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int sides[3] = {a, b, c};
    sort(sides, sides + 3);

    if (sides[0] + sides[1] > sides[2])
    {
        cout << sides[0] + sides[1] + sides[2] << '\n';
    }
    else
    {
        cout << (sides[0] + sides[1]) * 2 - 1 << '\n';
    }

    return 0;
}
