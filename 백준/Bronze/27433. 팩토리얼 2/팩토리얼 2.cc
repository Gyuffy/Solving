#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	long long ans;

	cin >> N;

	ans = 1;

	for (int i = N; i > 1; i--)
	{
		ans *= i;
	}

	cout << ans << '\n';

	return 0;
}