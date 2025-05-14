#include <iostream>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans;

	cin >> N;

	if (N == 2)
	{
		ans = 1;
	}
	else if (N == 3)
	{
		ans = 3;
	}
	else
	{
		ans = N * 3 - 4;
	}

	cout << ans << "\n";

	return 0;
}