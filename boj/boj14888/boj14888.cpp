// boj 14888번 연산자 끼워넣기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, tmp, max_val, min_val;
int numbers[11];
int ops[4];
int path[10];

void input()
{
	// 초기화
	for (int i = 0; i < 10; i++)
	{
		path[i] = -1;
	}

	max_val = -1000000000;
	min_val = 1000000000;

	// 입력
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> ops[i];
	}

	tmp = numbers[0];
}

void rec(int lev)
{
	// 종료 조건
	if (lev == N - 1)
	{
		for (int i = 1; i < N; i++)
		{
			if (path[i - 1] == 0)
			{
				tmp += numbers[i];
			}
			else if (path[i - 1] == 1)
			{
				tmp -= numbers[i];
			}
			else if (path[i - 1] == 2)
			{
				tmp *= numbers[i];
			}
			else
			{
				tmp /= numbers[i];
			}
		}

		if (tmp > max_val)
		{
			max_val = tmp;
		}

		if (tmp < min_val)
		{
			min_val = tmp;
		}

		tmp = numbers[0];

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (ops[i] == 0)
		{
			continue;
		}

		path[lev] = i;
		ops[i] -= 1;
		rec(lev + 1);
		path[lev] = -1;
		ops[i] += 1;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	input();
	rec(0);
	cout << max_val << "\n" << min_val << "\n";

	return 0;
}