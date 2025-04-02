#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string str;
string strs[101];
int m;
int letters[26];

void init()
{
	memset(letters, 0, sizeof(letters));
}

void input()
{
	cin >> str;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> strs[i];
	}
}

void solve()
{
	for (int i = 0; i < m; i++)
	{
		string now = strs[i];

		memset(letters, 0, sizeof(letters));

		for (int j = 0; j < str.length(); j++)
		{
			letters[str[j] - 'A']++;
		}

		for (int j = 0; j < now.length(); j++)
		{
			if (letters[now[j] - 'A'] == 0)
			{
				cout << "NO\n";
				break;
			}
			else
			{
				letters[now[j] - 'A']--;
				
				if (j == now.length() - 1)
				{
					cout << "YES\n";
					break;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, tc;

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
	}


	return 0;
}