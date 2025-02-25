#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, C, maxProfit;
int MAP[10][10];
int exps[10][10];

struct Point
{
	int y, x;
};

void init()
{
	maxProfit = 0;
}

void input()
{
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			exps[i][j] = MAP[i][j] * MAP[i][j];
		}
	}
}

void dfs(Point cur, int lev, int sum, int profit)
{
	if (lev == M)
	{
		if (maxProfit < profit)
		{
			maxProfit = profit;
		}
	}
	
	for (int i = 0; i < 2; i++)
	{
		sum += MAP[cur.y][cur.x] * i;
		if (sum > C)
		{
			sum -= MAP[cur.y][cur.x] * i;
			continue;
		}
		
		profit += exps[cur.y][cur.x] * i;
		int nx = cur.x + 1;
		dfs({ cur.y, nx }, lev + 1, sum, profit);
		sum -= MAP[cur.y][cur.x] * i;
		profit -= exps[cur.y][cur.x] * i;
	}
}

void solve()
{
	// MAP을 순회하면서 일꾼 A의 위치를 지정
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N - M; j++)
		{
			Point A = { i, j };
			// 일꾼 B의 위치를 지정
			for (int r = A.y; r < N; r++)
			{
				// 일꾼 A와 B가 같은 행인 경우 B의 x좌표는 "A의 x좌표 + M"
				for (int c = (i == A.y) ? (A.x + M) : 0; c <= N - M; c++)
				{
					Point B = { r, c };
					for (int k = 0; k < M; k++)
					{
						dfs(A, 0, 0, 0);
					}
				}
			}
		}
	}
}

int main()
{
	freopen("sample_input.txt", "r", stdin);
	int T, test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		solve();
	}

	return 0;
}