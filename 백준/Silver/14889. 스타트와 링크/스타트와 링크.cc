#include <iostream>
#include <algorithm>
using namespace std;

int N;
int table[20][20];
bool pick[20];
int best = 21e8;

void dfs(int idx, int cnt)
{
    if (cnt == N / 2)
    {
        int sumA = 0, sumB = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                if (pick[i] && pick[j])
                    sumA += table[i][j] + table[j][i];
                else if (!pick[i] && !pick[j])
                    sumB += table[i][j] + table[j][i];
            }
        }
        best = min(best, abs(sumA - sumB));
        return;
    }

    for (int i = idx; i < N; ++i)
    {
        pick[i] = true;
        dfs(i + 1, cnt + 1);
        pick[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> table[i][j];

    pick[0] = true;
    dfs(1, 1);
    cout << best << '\n';
    return 0;
}
