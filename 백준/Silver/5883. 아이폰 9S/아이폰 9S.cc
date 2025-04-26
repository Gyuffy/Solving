#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, cnt;
	int capa[1000];
	set<int> s;
	set<int>::iterator iter = s.begin();
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> capa[i];
		s.insert(capa[i]);
	}

	int max_cnt = 1;
	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		int i = *iter;
		int start_idx = 0;
		cnt = 1;
		
		for (int j = 0; j < N; j++)
		{
			if (capa[j] != i)
			{
				start_idx = j;
				break;
			}
			if (j == N - 1)
			{
				start_idx = N;
			}
		}

		int prev = capa[start_idx];

		for (int j = start_idx + 1; j < N; j++)
		{
			if (capa[j] == i)
				continue;

			if (capa[j] == prev)
			{
				prev = capa[j];
				cnt++;
				max_cnt = max_cnt > cnt ? max_cnt : cnt;
			}
			
			if (capa[j] != prev)
			{
				prev = capa[j];
				cnt = 1;
			}
		}
	}

	cout << max_cnt << "\n";

	return 0;
}