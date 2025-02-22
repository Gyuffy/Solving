#define _CRT_SECURE_NO_WARNINGS
#define N_MAX 51
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point
{
	int r;
	int c;
	int d = 2100000000;
};

int N, M;
int MAP[N_MAX][N_MAX];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int minDist = 21e8;
int path[13];
int used[13];
int temp;
Point home[100];
Point chicken[13];
int homeCnt = 0;
int chickenCnt = 0;

void input()
{
	memset(path, -1, sizeof(path));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
			{
				home[homeCnt].r = i;
				home[homeCnt].c = j;
				homeCnt++;
			}
			else if (MAP[i][j] == 2)
			{
				chicken[chickenCnt].r = i;
				chicken[chickenCnt].c = j;
				chickenCnt++;
			}
		}
	}
}

void calDist(int homeIdx, int chkIdx)
{
	int res = abs(chicken[chkIdx].r - home[homeIdx].r) + abs(chicken[chkIdx].c - home[homeIdx].c);
	home[homeIdx].d = min(home[homeIdx].d, res);
}

int findDist()
{
	int sum = 0;
	for (int i = 0; i < homeCnt; i++)
	{
		for (int j = 0; j < M; j++)
		{
			calDist(i, path[j]);
		}
		sum += home[i].d;
		home[i].d = 21e8;
	}
	return sum;
}

void dfs(int lev, int startIdx)
{
	if (lev == M)
	{
		temp = findDist();
		minDist = min(minDist, temp);
		return;
	}

	if (minDist == homeCnt)
	{
		return;
	}

	for (int i = startIdx; i < chickenCnt; i++)
	{
		if (used[i])
			continue;
		path[lev] = i;
		used[i] = 1;
		dfs(lev + 1, i + 1);
		path[lev] = -1;
		used[i] = 0;
	}
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	input();
	dfs(0, 0);
	cout << minDist << "\n";

	return 0;
}