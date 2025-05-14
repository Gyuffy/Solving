#include <iostream>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int res = N == 1 ? 1 : 2 * N - 2;
	cout << res << "\n";

	pair<int, int> pos = { 1, 1 };
	for (int i = 1; i <= N; i++)
	{
		pos.second = i;
		cout << pos.first << " " << pos.second << "\n";
	}

	pos.first = N;
	for (int i = 2; i <= N-1; i++)
	{
		pos.second = i;
		cout << pos.first << " " << pos.second << "\n";
	}

	return 0;
}