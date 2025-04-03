#include <iostream>
#include <set>

using namespace std;

set<int> used_num;
int N;
int id[300];

void init()
{
	used_num.clear();
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> id[i];
	}
}

void solve()
{
	int m = 1;

	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			int new_id = id[i] % m;

			if (used_num.find(new_id) == used_num.end())
			{
				used_num.insert(new_id);
			}
			else
			{
				used_num.clear();
				m++;
				break;
			}

			if (i == N - 1)
			{
				cout << m << '\n';
				return;
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