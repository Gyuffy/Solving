#include <iostream>

using namespace std;

int R, C;
char MAP[100][100];
char ans[100][100];
int dy[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1)
	{
		cin >> R >> C;

		if (R == 0 && C == 0)
			break;

		char str[101];
		for (int i = 0; i < R; i++)
		{
			cin >> str;

			for (int j = 0; j < C; j++)
			{
				MAP[i][j] = str[j];
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (MAP[i][j] == '*')
				{
					ans[i][j] = '*';
					continue;
				}

				int cnt = 0;

				for (int k = 0; k < 8; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 || ny >= R || nx < 0 || nx >= C)
						continue;

					if (MAP[ny][nx] == '*')
						cnt++;
				}

				ans[i][j] = cnt + '0';
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << ans[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}