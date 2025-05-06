#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t1[5], t2[5];
    int score1 = 0, score2 = 0;
    int points[5] = {6, 3, 2, 1, 2}; // TD, FG, Safety, PAT, 2pt

    for (int i = 0; i < 5; ++i)
    {
        cin >> t1[i];
        score1 += t1[i] * points[i];
    }

    for (int i = 0; i < 5; ++i)
    {
        cin >> t2[i];
        score2 += t2[i] * points[i];
    }

    cout << score1 << ' ' << score2 << '\n';
    return 0;
}
