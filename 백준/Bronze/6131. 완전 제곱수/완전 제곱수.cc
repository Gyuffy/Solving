#include <iostream>

using namespace std;

int N, cnt;
int exps[501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 500; i++)
	{
		exps[i] = i * i;
	}

	cin >> N;

	for (int i = 1; i <= 500; i++)
	{
		for (int j = i; j <= 500; j++)
		{
			if (exps[i] + N == exps[j])
			{
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}