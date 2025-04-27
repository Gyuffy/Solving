#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int puzzle[9][9];
int row_mask[9];
int col_mask[9];
int squ_mask[3][3];

void init()
{
	memset(row_mask, 0, sizeof(row_mask));
	memset(col_mask, 0, sizeof(col_mask));
	memset(squ_mask, 0, sizeof(squ_mask));
}

bool check(int r, int c)
{
	int squ_r = r / 3;
	int squ_c = c / 3;

	if (1 << puzzle[r][c] & row_mask[r])
		return false;

	if (1 << puzzle[r][c] & col_mask[c])
		return false;

	if (1 << puzzle[r][c] & squ_mask[squ_r][squ_c])
		return false;

	row_mask[r] |= 1 << puzzle[r][c];
	col_mask[c] |= 1 << puzzle[r][c];
	squ_mask[squ_r][squ_c] |= 1 << puzzle[r][c];

	return true;
}

string solve()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> puzzle[i][j];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (!check(i, j))
			{
				return "INCORRECT";
			}
		}
	}

	return "CORRECT";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		init();
		string ans = solve();
		cout << "Case " << tc << ": " << ans << "\n";
	}

	return 0;
}