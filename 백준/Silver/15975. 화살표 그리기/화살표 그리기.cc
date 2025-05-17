#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> pt[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> pt[i].first >> pt[i].second;
	}

	long long len_sum = 0;
	for (int i = 0; i < N; i++)
	{
		long long min_val = 21e8;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;

			if (pt[i].second == pt[j].second)
			{
				long long len = abs(pt[i].first - pt[j].first);
				min_val = min(min_val, len);
			}
		}

		len_sum += min_val != 21e8 ? min_val : 0;
	}

	cout << len_sum << "\n";

	return 0;
}