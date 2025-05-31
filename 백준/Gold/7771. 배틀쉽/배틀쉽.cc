#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Ship
{
    int len;
    int cnt;
};

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 10;
    int ord[N][N];
    pair<int, int> cell100;

    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            cin >> ord[r][c];
            if (ord[r][c] == 100)
            {
                cell100 = { r, c };
            }
        }
    }

    vector<string> board(N, string(N, '.'));
    vector<vector<bool>> forbid(N, vector<bool>(N, false));

    auto forbidAround = [&](int r, int c)
        {
            forbid[r][c] = true;
            for (int k = 0; k < 8; ++k)
            {
                int nr = r + dr[k], nc = c + dc[k];
                if (0 <= nr && nr < N && 0 <= nc && nc < N)
                {
                    forbid[nr][nc] = true;
                }
            }
        };

    int r100 = cell100.first, c100 = cell100.second;
    board[r100][c100] = '#';
    forbidAround(r100, c100);

    vector<Ship> fleet = { {4, 1}, {3, 2}, {2, 3}, {1, 3} };

    for (auto& ship : fleet)
    {
        while (ship.cnt--)
        {
            bool placed = false;
            for (int r = 0; r < N && !placed; ++r)
            {
                if (r % 2 == 1) continue;
                for (int c = 0; c + ship.len <= N && !placed; c += 2)
                {
                    bool ok = true;
                    for (int k = 0; k < ship.len && ok; ++k)
                    {
                        if (forbid[r][c + k]) ok = false;
                    }
                    if (ok)
                    {
                        for (int k = 0; k < ship.len; ++k)
                        {
                            board[r][c + k] = '#';
                            forbidAround(r, c + k);
                        }
                        placed = true;
                    }
                }
            }
        }
    }

    for (int r = 0; r < N; ++r)
    {
        cout << board[r] << '\n';
    }
    return 0;
}
