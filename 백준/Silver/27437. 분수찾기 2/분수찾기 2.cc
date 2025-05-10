#include <iostream>
using namespace std;

long long N;

bool valid(long long d)
{
	long long tmp = d * (d + 1) / 2;
	return tmp >= N;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long lo = 1, hi = 21e8, diag = 0;

	cin >> N;

	while (lo <= hi)
	{
		long long mid = (lo + hi) / 2;
		if (valid(mid))
		{
			diag = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	long long k = N - (diag * (diag - 1) / 2);
	long long upper, lower;

	if (diag & 1)
	{
		upper = diag - k + 1;
		lower = k;
	}
	else
	{
		upper = k;
		lower = diag - k + 1;
	}

	cout << upper << "/" << lower << "\n";

	return 0;
}