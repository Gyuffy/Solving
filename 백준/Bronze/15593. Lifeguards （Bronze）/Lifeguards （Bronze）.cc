#include <iostream>
#include <cstring>

using namespace std;

int N;
pair<int, int> shifts[101];
int table[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> shifts[i].first >> shifts[i].second;
	}

	int max_val = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == i) continue;
			for (int k = shifts[j].first; k < shifts[j].second; k++)
			{
				table[k] = 1;
			}
		}

		int cnt = 0;

		for (int j = 0; j <= 1000; j++)
		{
			if (table[j])
				cnt++;

			max_val = max_val > cnt ? max_val : cnt;
		}

		memset(table, 0, sizeof(table));
	}

	cout << max_val << '\n';

	return 0;
}