// SWEA 2112번 [모의 SW 역량테스트] 보호 필름
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int depth, width, cutline, flag, cnt, ans;
int film[13][20];
int origin[13][20];

void init()
{
	flag = 0;
	ans = 13;
	cnt = 0;
}

void input()
{
	cin >> depth >> width >> cutline;
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> film[i][j];
			origin[i][j] = film[i][j];
		}
	}
}

void treat(int lev)
{
	// 종료 조건
	if (lev == depth)
	{
		int pass = 0;
		int fail = 0;
		for (int i = 0; i < width; i++)
		{
			int seq = 1;
			if (fail == 1)	// 열이 하나라도 불합이면 더 볼 것도 없음 바로 중단
			{
				fail = 0;
				break;
			}
			for (int j = 1; j < depth; j++)
			{
				if (film[j][i] == film[j - 1][i])
				{
					seq++;
					if (seq == cutline && i == width - 1)
					{
						pass = 1;
						break;
					}
					else if(seq == cutline)	// 이번 열이 합격 기준을 통과하면 바로 다음 열로
					{
						break;
					}
				}
				else
				{
					seq = 1;
				}
				if (j == depth - 1 && seq < cutline)	// 합격 기준 미달인 열이 발생하면 바로 중단
				{
					fail = 1;
					break;
				}
			}
		}

		if (pass == 1)
		{
			pass = 0;
			if (cnt < ans)
			{
				ans = cnt;
				if (ans == 0)
				{
					flag = 1;
				}
			}
		}

		return;
	}

	// 종료 조건2
	if (flag == 1)
	{
		return;
	}

	// 종료 조건3
	if (cnt > cutline)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (i == 1)	// 한 레이어에 약품 A를 넣는 경우
		{
			for (int j = 0; j < width; j++)
			{
				film[lev][j] = 0;
			}
			cnt++;
		}
		else if (i == 2) // 한 레이어에 약품 B를 넣는 경우
		{
			for (int j = 0; j < width; j++)
			{
				film[lev][j] = 1;
			}
			cnt++;
		}

		treat(lev + 1);
		
		// 복귀
		if (i != 0)
		{
			for (int j = 0; j < width; j++)
			{
				film[lev][j] = origin[lev][j];
			}
			cnt--;
		}
		
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

		if (cutline == 1)
		{
			ans = 0;
		}

		treat(0);
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}