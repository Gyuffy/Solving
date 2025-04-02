#include <iostream>
#include <set>

using namespace std;

int m, cnt;
set<int> left_box;
set<int> right_box;

void init()
{
	cnt = 0;

	left_box.clear();
	right_box.clear();
}

void input()
{
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int time_log;
		cin >> time_log;
		left_box.insert(time_log);
	}

	for (int i = 0; i < m; i++)
	{
		int time_log;
		cin >> time_log;
		right_box.insert(time_log);
	}
}

void solve()
{
	for (set<int>::iterator iter = left_box.begin(); iter != left_box.end(); iter++)
	{
		int t = *iter;

		if (left_box.find(t + 500) == left_box.end())
			continue;
		if (right_box.find(t + 1000) == right_box.end())
			continue;
		if (right_box.find(t + 1500) == right_box.end())
			continue;

		cnt++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc, T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		cout << cnt << '\n';
	}

	return 0;
}