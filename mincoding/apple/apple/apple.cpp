// 민코딩 사과 먹기 게임
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, last_apple, ans, cnt;
int MAP[10][10];

struct Point
{
	int y, x;
}sp;

int move_dir;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

struct Apple
{
	int y, x;
	int idx;
	bool isClear = false;
}apples[10];

void init()
{
	ans = 0;
	cnt = 0;
	sp.y = 0;
	sp.x = 0;
	move_dir = 3;
}

bool compare(Apple a, Apple b)
{
	return a.idx < b.idx;
}

void input()
{
	int max_val = 0;
	int tmp_idx = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] >= 1)
			{
				apples[tmp_idx].idx = MAP[i][j];
				apples[tmp_idx].y = i;
				apples[tmp_idx].x = j;
				apples[tmp_idx].isClear = false;
				tmp_idx++;
			}
			if (MAP[i][j] > max_val)
			{
				last_apple = MAP[i][j];
				max_val = last_apple;
			}
		}
	}

	sort(apples, apples + last_apple, compare);
}

void solve()
{
	int target_idx = 0;
	while (!apples[last_apple - 1].isClear)
	{
		if (move_dir == 0)
		{
			if (target_idx == 6)
			{
				int de = 1;
			}
			if (apples[target_idx].x > sp.x && apples[target_idx].y <= sp.y)
			{
				cnt += 1;
				move_dir = 3;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else if (apples[target_idx].x > sp.x && apples[target_idx].y > sp.y)
			{
				cnt += 2;
				move_dir = 1;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else
			{
				cnt += 3;
				move_dir = 2;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
		}
		else if (move_dir == 1)
		{
			if (target_idx == 5)
			{
				int de = 1;
			}
			if (apples[target_idx].x < sp.x && apples[target_idx].y >= sp.y)
			{
				cnt += 1;
				move_dir = 2;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else if(apples[target_idx].x < sp.x && apples[target_idx].y < sp.y)
			{
				cnt += 2;
				move_dir = 0;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else
			{
				cnt += 3;
				move_dir = 3;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
		}
		else if (move_dir == 2)
		{
			if (apples[target_idx].y < sp.y && apples[target_idx].x <= sp.x)
			{
				cnt += 1;
				move_dir = 0;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else if (apples[target_idx].y < sp.y && apples[target_idx].x > sp.x)
			{
				cnt += 2;
				move_dir = 3;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else
			{
				cnt += 3;
				move_dir = 1;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
		}
		else
		{
			if (apples[target_idx].y > sp.y && apples[target_idx].x >= sp.x)
			{
				cnt += 1;
				move_dir = 1;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else if (apples[target_idx].y > sp.y && apples[target_idx].x < sp.x)
			{
				cnt += 2;
				move_dir = 2;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
			else
			{
				cnt += 3;
				move_dir = 0;
				sp.y = apples[target_idx].y;
				sp.x = apples[target_idx].x;
				apples[target_idx].isClear = true;
				target_idx += 1;
			}
		}
	}
	ans = cnt;
}

int main()
{
	int T, tc;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}