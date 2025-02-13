// SWEA 1767. [SW Test 샘플문제] 프로세서 연결하기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, cnt, ans, max_val, num_of_core, len_of_wire;
int cells[12][12];
int origin[12][12];

struct Core
{
	int y, x;
	int p;	// core에 연결한 power의 면
}cores[12];

void init()
{
	ans = 0;
	cnt = 0;
	max_val = 0;
	len_of_wire = 0;
}

void input()
{
	cin >> N;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cells[i][j];
			origin[i][j] = cells[i][j];
			if (cells[i][j] == 1)
			{
				cores[idx].y = i;
				cores[idx].x = j;
				cores[idx].p = -1;	// core에 아무런 전원도 인가하지 않은 상태
				idx++;
			}
		}
	}
	num_of_core = idx;
}

bool cannot_connect(int idx, int power)
{
	// power와 이미 인접한 cell인 경우
	if (cores[idx].y == 0 || cores[idx].y == N - 1 || cores[idx].x == 0 || cores[idx].x == N - 1)
	{
		return false;
	}

	// 연결해야 하는 power가 위쪽 방향인 경우
	if (power == 0)
	{
		for (int i = 0; i < cores[idx].y; i++)
		{
			if (cells[i][cores[idx].x] >= 1)
			{
				return true;
			}
		}
	}

	// 연결해야 하는 power가 오른쪽 방향인 경우
	else if (power == 1)
	{
		for (int i = cores[idx].x + 1; i < N; i++)
		{
			if (cells[cores[idx].y][i] >= 1)
			{
				return true;
			}
		}
	}

	// 연결해야 하는 power가 아래쪽 방향인 경우
	else if (power == 2)
	{
		for (int i = cores[idx].y + 1; i < N; i++)
		{
			if (cells[i][cores[idx].x] >= 1)
			{
				return true;
			}
		}
	}

	// 연결해야 하는 power가 왼쪽 방향인 경우
	else if (power == 3)
	{
		for (int i = 0; i < cores[idx].x; i++)
		{
			if (cells[cores[idx].y][i] >= 1)
			{
				return true;
			}
		}
	}

	return false;
}

void connect_wire(int idx, int power)
{
	// power와 이미 인접한 cell인 경우
	if (cores[idx].y == 0 || cores[idx].y == N - 1 || cores[idx].x == 0 || cores[idx].x == N - 1)
	{
		return;
	}

	// 연결해야 하는 power가 위쪽 방향인 경우
	if (power == 0)
	{
		for (int i = 0; i < cores[idx].y; i++)
		{
			cells[i][cores[idx].x] = 2;
			len_of_wire++;
		}
	}

	// 연결해야 하는 power가 오른쪽 방향인 경우
	else if (power == 1)
	{
		for (int i = cores[idx].x + 1; i < N; i++)
		{
			cells[cores[idx].y][i] = 2;
			len_of_wire++;
		}
	}

	// 연결해야 하는 power가 아래쪽 방향인 경우
	else if (power == 2)
	{
		for (int i = cores[idx].y + 1; i < N; i++)
		{
			cells[i][cores[idx].x] = 2;
			len_of_wire++;
		}
	}

	// 연결해야 하는 power가 왼쪽 방향인 경우
	else if (power == 3)
	{
		for (int i = 0; i < cores[idx].x; i++)
		{
			cells[cores[idx].y][i] = 2;
			len_of_wire++;
		}
	}
}

void select_power(int lev)
{
	if (lev == num_of_core)
	{
		if (max_val < cnt)
		{
			max_val = cnt;
			ans = len_of_wire;
		}
		if (max_val == cnt && ans > len_of_wire)
		{
			ans = len_of_wire;
		}
		len_of_wire = 0;
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cells[i][j] = origin[i][j];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (cannot_connect(lev, i))
		{
			continue;
		}
		cores[lev].p = i;
		connect_wire(lev, i);
		cnt++;
		select_power(lev + 1);
		cores[lev].p = -1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		init();
		input();
		select_power(0);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}