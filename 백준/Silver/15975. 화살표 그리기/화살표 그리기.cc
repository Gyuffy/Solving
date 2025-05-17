#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> pt[100000];

bool sorting(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> pt[i].first >> pt[i].second;
	}

	sort(pt, pt + N, sorting);

	long long len_sum = 0;
	len_sum += pt[1].second == pt[0].second ? pt[1].first - pt[0].first : 0;
	len_sum += pt[N - 1].second == pt[N - 2].second ? pt[N - 1].first - pt[N - 2].first : 0;
	for (int i = 1; i < N - 1; i++)
	{
		if (pt[i].second != pt[i - 1].second && pt[i].second != pt[i + 1].second)
			continue;
		if (pt[i].second == pt[i - 1].second && pt[i].second == pt[i + 1].second)
		{
			len_sum += min(pt[i].first - pt[i - 1].first, pt[i + 1].first - pt[i].first);
		}
		else if (pt[i].second == pt[i - 1].second)
		{
			len_sum += pt[i].first - pt[i - 1].first;
		}
		else
		{
			len_sum += pt[i + 1].first - pt[i].first;
		}
	}

	cout << len_sum << "\n";

	return 0;
}