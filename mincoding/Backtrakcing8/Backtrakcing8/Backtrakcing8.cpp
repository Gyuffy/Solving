// Backtracking의 탑 8번 다빈치 타워
#include <iostream>

using namespace std;

int N, M;
int max_val = 0;

int path[5][5];
int temp[5][5];

int sum_col[5];

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> path[i][j];
		}
	}
}

void rotate_windows(int idx)
{
	for (int i = 0; i < M; i++)
	{
		if (i == M - 1)
		{
			temp[idx][0] == path[idx][M - 1];
		}
		else
		{
			temp[idx][i + 1] = path[idx][i];
		}
	}
	for (int i = 0; i < M; i++)
	{
		path[idx][i] = temp[idx][i];
	}
}

void calculate_score()
{
	int vinci_score = 1;

	// 각 열마다의 합을 구하기
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum_col[i] += path[j][i];
		}
	}
	
	// 이제 각 열마다의 합을 곱하기
	for (int i = 0; i < M; i++)
	{
		vinci_score *= sum_col[i];
	}

	if (max_val < vinci_score)
	{
		max_val = vinci_score;
	}
}

void rot(int lev)
{
	if (lev == M - 1)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		rotate_windows(i);
	}
	calculate_score();
}

int main()
{
	input();
	rot(0);


	return 0;
}