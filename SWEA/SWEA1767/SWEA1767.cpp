// SWEA 1767번 [SW Test 샘플문제] 프로세서 연결하기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Core
{
	int y, x;
	int p;
}cores[12];

int N, ans, cnt, len, num_of_core;
int max_val, min_val;
int cells[12][12];

void init()
{
	ans = 0;
	cnt = 0;
	max_val = 0;
	min_val = 144;
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
			if (cells[i][j] == 1 && i != 0 && j != 0 && i != N - 1 && j != N - 1)
			{
				cores[idx].y = i;
				cores[idx].x = j;
				cores[idx].p = -1;
				idx++;
			}
		}
	}
	num_of_core = idx;
}

bool cannot_connect(int idx)
{
	// power와 연결하지 않는 경우
	if (cores[idx].p == 0)
	{
		return true;
	}

	// 연결해야 하는 power가 위쪽 방향인 경우
	else if (cores[idx].p == 1)
	{
		for (int i = cores[idx].y - 1; i >= 0; i--)
		{
			if (cells[i][cores[idx].x] >= 1)
			{
				return true;
			}
		}
	}

	// 연결해야 하는 power가 아래쪽 방향인 경우
	else if (cores[idx].p == 2)
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
	else if (cores[idx].p == 3)
	{
		for (int i = 0; i < cores[idx].x; i++)
		{
			if (cells[cores[idx].y][i] >= 1)
			{
				return true;
			}
		}
	}

	// 연결해야 하는 power가 오른쪽 방향인 경우
	else if (cores[idx].p == 4)
	{
		for (int i = cores[idx].x + 1; i < N; i++)
		{
			if (cells[cores[idx].y][i] >= 1)
			{
				return true;
			}
		}
	}

	return false;
}

void install_wire(int idx, int power)
{
	// 연결 안(혹은 못)하는 경우
	if (power == 0)
	{
		return;
	}

	// 연결해야 하는 power가 위쪽 방향인 경우
	if (power == 1)
	{
		for (int i = 0; i < cores[idx].y; i++)
		{
			cells[i][cores[idx].x] = 2;
			len++;
		}
		cnt++;
	}

	// 연결해야 하는 power가 아래쪽 방향인 경우
	else if (power == 2)
	{
		for (int i = cores[idx].y + 1; i < N; i++)
		{
			cells[i][cores[idx].x] = 2;
			len++;
		}
		cnt++;
	}

	// 연결해야 하는 power가 왼쪽 방향인 경우
	else if (power == 3)
	{
		for (int i = 0; i < cores[idx].x; i++)
		{
			cells[cores[idx].y][i] = 2;
			len++;
		}
		cnt++;
	}

	// 연결해야 하는 power가 오른쪽 방향인 경우
	else if (power == 4)
	{
		for (int i = cores[idx].x + 1; i < N; i++)
		{
			cells[cores[idx].y][i] = 2;
			len++;
		}
		cnt++;
	}
}

void disconnect(int idx, int power)
{
	if (power == 0)
	{
		return;
	}

	else if (power == 1)
	{
		for (int i = 0; i < cores[idx].y; i++)
		{
			cells[i][cores[idx].x] = 0;
			len--;
		}
		cnt--;
	}

	else if (power == 2)
	{
		for (int i = cores[idx].y + 1; i < N; i++)
		{
			cells[i][cores[idx].x] = 0;
			len--;
		}
		cnt--;
	}

	else if (power == 3)
	{
		for (int i = 0; i < cores[idx].x; i++)
		{
			cells[cores[idx].y][i] = 0;
			len--;
		}
		cnt--;
	}

	else if (power == 4)
	{
		for (int i = cores[idx].x + 1; i < N; i++)
		{
			cells[cores[idx].y][i] = 0;
			len--;
		}
		cnt--;
	}
}

void connect(int lev)
{
	if (lev == num_of_core)
	{
		if (max_val < cnt)
		{
			ans = len;
			max_val = cnt;
		}

		else if (max_val == cnt && ans > len)
		{
			ans = len;
		}

		return;
	}

	for (int i = 0; i < 5; i++)
	{
		cores[lev].p = i;

		if (cannot_connect(lev))
		{
			cores[lev].p = 0;
		}

		if (num_of_core - lev + cnt < max_val)
		{
			continue;
		}

		install_wire(lev, cores[lev].p);

		connect(lev + 1);

		disconnect(lev, cores[lev].p);

		cores[lev].p = -1;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		connect(0);
		cout << "#" << test_case << " " << ans << "\n";
	}
}