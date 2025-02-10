// SWEA 2383. [모의 SW 역량테스트] 점심 식사시간
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

struct Stair
{
	int y, x;
	int num;
	int capa = 3;
}stairs[2];

struct Person
{
	int y, x;
	int arrive;
	int inStair;
	bool isGoal;
	int stair_num;
}people[10];

int T;
int test_case;

int N;
int plane[10][10];

int nop = 0;
int goal_cnt = 0;

int moving_time = 0;
int min_time = 1000000;

int path[10];	// 몇번 계단을 이용하는지
int de_path[10];

bool compare(Person a, Person b)
{
	return a.arrive < b.arrive;
}

void init()
{
	nop = 0;
	goal_cnt = 0;
	moving_time = 0;
	min_time = 1000000;

	for (int i = 0; i < 2; i++)
	{
		stairs[i].capa = 3;
	}

	for (int i = 0; i < 10; i++)
	{
		people[i].arrive = 0;
		people[i].isGoal = false;
		people[i].inStair = 0;
	}
}

void input()
{

	cin >> N;

	int nos = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> plane[i][j];

			// 사람의 정보를 입력 받는다.
			if (plane[i][j] == 1)
			{
				people[nop].y = i;
				people[nop].x = j;
				nop++;
			}

			// 계단의 정보를 입력 받는다.
			if (plane[i][j] >= 2)
			{
				stairs[nos].y = i;
				stairs[nos].x = j;
				stairs[nos].num = plane[i][j];
				nos++;
			}
		}
	}
}

void simulate()
{
	// 시뮬 돌릴 때마다 초기화
	moving_time = 0;
	goal_cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		stairs[i].capa = 3;
	}

	for (int i = 0; i < 10; i++)
	{
		people[i].arrive = 0;
		people[i].isGoal = false;
		people[i].inStair = 0;
	}

	// 각 계단과의 거리를 계산
	for (int i = 0; i < nop; i++)
	{
		if (path[i] == 0)
		{
			people[i].arrive += abs(people[i].y - stairs[0].y);
			people[i].arrive += abs(people[i].x - stairs[0].x);
			people[i].stair_num = path[i];
		}
		else if (path[i] == 1)
		{
			people[i].arrive += abs(people[i].y - stairs[1].y);
			people[i].arrive += abs(people[i].x - stairs[1].x);
			people[i].stair_num = path[i];
		}
	}

	sort(people, people + nop, compare);

	while (goal_cnt != nop)
	{
		for (int i = 0; i < nop; i++)
		{
			// 이동을 이미 완료한 사람이라면 패스
			if (people[i].isGoal)
			{
				continue;
			}

			// 계단으로 이동할 때
			if (people[i].arrive > 0)
			{
				people[i].arrive--;
			}

			// 계단 입구에 도착했을 때
			else if (people[i].arrive == 0 && people[i].inStair == 0)
			{
				if (stairs[people[i].stair_num].capa == 0)
				{
					continue;
				}
				else
				{
					stairs[people[i].stair_num].capa--;
					people[i].inStair = stairs[people[i].stair_num].num;
				}
			}

			// 계단 안에 있는 경우
			else if (people[i].inStair > 0)
			{
				people[i].inStair--;

				// 이동을 완료한 경우
				if (people[i].inStair == 0)
				{
					people[i].isGoal = true;
					stairs[people[i].stair_num].capa++;
					goal_cnt++;
					if (goal_cnt == nop)
					{
						break;
					}
				}
			}
		}
		moving_time++;
	}

	if (moving_time < min_time)
	{
		min_time = moving_time;
		for (int i = 0; i < 10; i++)
		{
			de_path[i] = path[i];
		}
	}

}

void dfs(int lev)
{
	if (lev == nop)
	{
		simulate();

		return;
	}

	for (int i = 0; i < 2; i++)
	{
		path[lev] = i;
		dfs(lev + 1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		dfs(0);
		cout << "#" << test_case << " " << min_time << "\n";
	}

	return 0;
}