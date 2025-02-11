// 민코딩 Backtracking의 탑 7번 프로듀스 101배수
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int numbers[10];

int ans = 0;
int path[9];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
}

void calculate(int op)
{
	if (op == N - 1)
	{
		ans = numbers[0];
		for (int i = 1; i < N; i++)
		{
			if (path[i - 1] == 0)
			{
				ans *= numbers[i];
			}
			else if (path[i - 1] == 1)
			{
				ans += numbers[i];
			}
			else if (path[i - 1] == 2)
			{
				ans -= numbers[i];
			}
		}

		if (ans % 101 == 0 && abs(ans) >= 101)
		{
			for (int i = 0; i < N; i++)
			{
				cout << numbers[i];
				if (i == N - 1)
				{
					cout << "\n";
				}
				else if (path[i] == 0)
				{
					cout << "*";
				}
				else if (path[i] == 1)
				{
					cout << "+";
				}
				else if (path[i] == 2)
				{
					cout << "-";
				}
			}
		}

		return;
	}

	for (int i = 0; i < 3; i++)
	{
		path[op] = i;
		calculate(op + 1);
	}
}

int main()
{
	input();
	calculate(0);

	return 0;
}