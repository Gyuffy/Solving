#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int robot = -1;
    int box   = -1;
    int goal  = -1;

    for (int i = 0; i < 10; ++i)
    {
        if (s[i] == '@')
        {
            robot = i;
        }
        else if (s[i] == '#')
        {
            box = i;
        }
        else if (s[i] == '!')
        {
            goal = i;
        }
    }

    bool boxBetween =
        (robot < box && box < goal) || (goal < box && box < robot);

    if (boxBetween)
    {
        cout << abs(robot - goal) - 1 << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}
