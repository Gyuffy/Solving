#include <iostream>
#include <string>
using namespace std;

int N, M;

string solve()
{
	cin >> N >> M;
	while (N--)
	{
		if (!(M & (1 << N)))
			return "OFF";
	}

	return "ON";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		cout << "#" << tc << " " << solve() << "\n";
	}

	return 0;
}