#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int T, test_case, N;
int taste_a, taste_b;

int table[16][16];
int choose_a[16];

int diff, min_val;

void init()
{
	min_val = 20001;

	for (int i = 0; i < 16; i++)
	{
		choose_a[i] = 0;
	}
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> table[i][j];
		}
	}
}

void cook(int row, int cnt)
{
	// A가 N/2개의 요리 재료 선택을 끝내면 재귀 종료
	if (cnt == N / 2)
	{
		// 시너지 구하기 시작
		taste_a = 0;
		taste_b = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 두 가지의 재료가 동일하면 0이므로
				if (i == j)
				{
					continue;
				}

				if (choose_a[i] && choose_a[j])
				{
					taste_a += table[i][j];
				}
				else if (!choose_a[i] && !choose_a[j])
				{
					taste_b += table[i][j];
				}
			}
		}

		diff = (taste_a - taste_b) > 0 ? taste_a - taste_b : taste_b - taste_a;
		if (diff < min_val)
		{
			min_val = diff;
		}

		return;
	}

	// row가 마지막까지 도달했으면 다시 재귀 종료
	if (row >= N)
	{
		return;
	}

	choose_a[row] = 1;
	cook(row + 1, cnt + 1);	// A가 선택한 경우
	choose_a[row] = 0;
	cook(row + 1, cnt);		// B가 선택한 경우
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		cook(0, 0);
		cout << "#" << test_case << " " << min_val << "\n";
	}

	return 0;
}