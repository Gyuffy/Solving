#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M, cnt;
string str;
map<string, int> m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		cin >> str;
		m[str]++;
		cnt = m[str] == 2 ? cnt + 1 : cnt;
	}

	cout << cnt << "\n";

	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second == 2)
		{
			cout << iter->first << "\n";
		}
	}

	return 0;
}