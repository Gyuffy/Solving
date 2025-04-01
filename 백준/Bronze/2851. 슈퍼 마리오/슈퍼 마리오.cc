#include <iostream>

using namespace std;

int mushrooms[10];
int min_val = 21e8;
int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 10; i++)
	{
		cin >> mushrooms[i];
	}

	for (int i = 0; i < 10; i++)
	{
		int sum = 0;
		for (int j = 0; j <= i; j++)
		{
			sum += mushrooms[j];
		}

		int temp = (sum - 100) > 0 ? sum - 100 : -1 * (sum - 100);

		if (min_val >= temp)
		{
			min_val = temp;
			ans = sum;
		}
	}

	cout << ans << '\n';

	return 0;
}