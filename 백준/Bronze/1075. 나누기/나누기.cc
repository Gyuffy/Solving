#include <iostream>
using namespace std;

int N, F, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> F;

	N /= 100;
	N *= 100;

	for (int i = 0; i <= 99; i++)
	{
		int temp = N + i;
		if (temp % F == 0)
		{
			ans = i;
			break;
		}
	}

	if (ans < 10)
	{
		cout << '0' << ans;
	}
	else
	{
		cout << ans;
	}

	return 0;
}