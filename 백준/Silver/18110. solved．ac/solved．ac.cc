#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "0\n";
		return 0;
	}

	float tmp = n * 0.15;
	int del = (int)tmp;
	int digit = (int)(tmp * 10) % 10;

	del = digit >= 5 ? del + 1 : del;

	vector<int> diff(n);
	for (int i = 0; i < n; i++)
	{
		cin >> diff[i];
	}

	sort(diff.begin(), diff.end());

	int sum = 0;
	for (int i = del; i < n - del; i++)
	{
		sum += diff[i];
	}

	tmp = (float)sum / (n - 2 * del);
	int ans = (int)tmp;
	digit = (int)(tmp * 10) % 10;

	ans = digit >= 5 ? ans + 1 : ans;

	cout << ans << "\n";

	return 0;
}