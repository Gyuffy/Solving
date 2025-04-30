#include <iostream>
using namespace std;

struct Example
{
	int num;
	int s;
	int b;
}example[100];

int N, ans;
int valid[988];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 123; i <= 987; i++)
	{
		valid[i] = 1;

		int temp = i;
		int a = i / 100, b = (i / 10) % 10, c = i % 10;
		if (a == b || b == c || c == a)
		{
			valid[i] = 0;
		}

		while (temp != 0)
		{
			if (temp % 10 == 0)
			{
				valid[i] = 0;
				break;
			}
			temp /= 10;
		}
	}
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> example[i].num >> example[i].s >> example[i].b;
	}

	for (int i = 123; i <= 987; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int strike = 0, ball = 0;
			int tgt = example[j].num;
			int cur = i;
			int digit_a[3], digit_b[3];
			int mask = 0;
			for (int k = 0; k < 3; k++)
			{
				digit_a[k] = tgt % 10;
				digit_b[k] = cur % 10;

				if (digit_a[k] == digit_b[k])
				{
					strike++;
				}
				else
				{
					mask |= (1 << digit_a[k]);
				}

				tgt /= 10;
				cur /= 10;
			}
			for (int k = 0; k < 3; k++)
			{
				if (mask & (1 << digit_b[k]))
					ball++;
			}

			if (example[j].s != strike || example[j].b != ball)
			{
				valid[i] = 0;
				break;
			}
		}

		if (valid[i] == 1)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}