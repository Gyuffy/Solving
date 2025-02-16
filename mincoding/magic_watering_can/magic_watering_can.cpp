// 민코딩 기출 마법의 물뿌리개
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, day, cnt, ans, peak, stored;
int trees[100];

void init()
{
	day = 0;
	cnt = 0;
	ans = 0;
	peak = 0;
	stored = 0;
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
		if (trees[i] > peak)
		{
			peak = trees[i];
		}
	}

	sort(trees, trees + N, greater<int>());
}

void simulate()
{
	for (int i = 0; i < N; i++)
	{
		if (trees[i] == peak)
		{
			cnt++;
		}
	}
	if (cnt == N)
		return;

	while (true)
	{
		day++;
		for (int i = 0; i < N; i++)
		{
			if (trees[i] == peak)
				continue;

			int tmp = peak - trees[i];

			if (tmp >= 3)
			{
				trees[i] += 2 - (day % 2);
				break;
			}
			else
			{
				if (tmp % 2 == day % 2)
				{
					trees[i] += 2 - (day % 2);
					if (trees[i] == peak)
					{
						cnt++;
					}
					break;
				}
				else if (i == N - 1)
				{
					stored += 2 - (day % 2);
				}
			}
		}
		
		if (cnt == N)
		{
			return;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	int T, tc;
	cin >> T;

	for (tc = 1; tc <= T; tc++)
	{
		init();
		input();
		simulate();
		cout << "#" << tc << " " << day << "\n";
	}

	return 0;
}