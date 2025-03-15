#include <iostream>
using namespace std;

int N, cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			for (int k = 1; k < N; k++)
			{
				if (i % 2 == 0 && i + j + k == N && k >= j + 2)
				{
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}