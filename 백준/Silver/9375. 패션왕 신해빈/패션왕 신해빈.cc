#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M, ans;
string name, type;
map<string, int> m;

void input()
{
	ans = 1;
	m.clear();

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> name >> type;
		m[type]++;
	}
}

void solve()
{
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		ans *= iter->second + 1;
	}

	ans -= 1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		input();
		solve();
		cout << ans << "\n";
	}

	return 0;
}