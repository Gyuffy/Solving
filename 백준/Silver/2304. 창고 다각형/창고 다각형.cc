#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	v.reserve(N);

	for (int i = 0; i < N; i++)
	{
		int L, H;
		cin >> L >> H;
		v.push_back({ L, H });
	}

	sort(v.begin(), v.end());

	int max_height = 0;
	for (const auto& p : v)
	{
		max_height = max_height > p.second ? max_height : p.second;
	}

	int first_max = -1, last_max = -1;
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (v[i].second == max_height)
		{
			if (first_max == -1)
				first_max = i;
			last_max = i;
		}
	}

	long long area = 0;

	int cur_h = v[0].second;
	int cur_x = v[0].first;
	for (int i = 1; i <= first_max; i++)
	{
		if (v[i].second >= cur_h)
		{
			area += 1LL * cur_h * (v[i].first - cur_x);
			cur_h = v[i].second;
			cur_x = v[i].first;
		}
	}

	cur_h = v.back().second;
	cur_x = v.back().first;
	for (int i = (int)v.size() - 2; i >= last_max; i--)
	{
		if (v[i].second >= cur_h)
		{
			area += 1LL * cur_h * (cur_x - v[i].first);
			cur_h = v[i].second;
			cur_x = v[i].first;
		}
	}

	area += 1LL * max_height * (v[last_max].first - v[first_max].first + 1);

	cout << area << "\n";

	return 0;
}
