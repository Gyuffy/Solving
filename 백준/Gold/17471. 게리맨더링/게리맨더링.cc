#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, ans;
int arr[10][10];	// 인접 행렬
int vote[10];	// 각 마을의 유권자 수
int path[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };	// 지역구 A일 시 0, 지역구 B일 시 1
int visited[10];

void init()
{
	ans = 21e8;
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> vote[i];
	}

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int tmp;
			cin >> tmp;
			arr[i][tmp - 1] = 1;
			arr[tmp - 1][i] = 1;
		}
	}
	
}

bool bfs(int st, int cutline)
{
	int cnt = 0;
	queue<int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (path[cur] == path[st])
			cnt++;

		for (int i = 0; i < N; i++)
		{
			if (arr[cur][i] == 0)
				continue;
			if (visited[i] == 1)
				continue;
			if (path[i] != path[st])
				continue;

			int next = i;
			visited[next] = 1;
			q.push(next);
		}
	}

	if (cnt == cutline)
		return true;
	else
		return false;
}

void dfs(int lev, int cnt)
{
	// 종료 조건 : 모든 지역구의 배정이 끝난 경우
	if (lev == N)
	{
		if (cnt == N || cnt == 0)
			return;

		int standA;
		for (int i = 0; i < N; i++)
		{
			if (path[i] == 0)
			{
				standA = i;
				break;
			}
		}
		bool passA = bfs(standA, cnt);

		int standB;
		for (int i = 0; i < N; i++)
		{
			if (path[i] == 1)
			{
				standB = i;
				break;
			}
		}
		bool passB = bfs(standB, N - cnt);



		if (path[0] == 0 && path[1] == 1 && path[2] == 0 && path[3] == 1)
		{
			int de = 1;
		}

		if (passA && passB)
		{
			int sumA = 0;
			int sumB = 0;

			for (int i = 0; i < N; i++)
			{
				if (path[i] == 0)
				{
					sumA += vote[i];
				}
				else
				{
					sumB += vote[i];
				}
			}

			int temp = sumA - sumB > 0 ? sumA - sumB : sumB - sumA;
			ans = temp < ans ? temp : ans;
		}

		for (int i = 0; i < N; i++)
		{
			visited[i] = 0;
		}

		return;
	}

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
			cnt++;

		path[lev] = i;
		dfs(lev + 1, cnt);
		if (i == 0)
			cnt--;
		path[lev] = -1;
	}
}

void solve()
{
	dfs(0, 0);
	if (ans == 21e8)
		ans = -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	init();
	input();
	solve();
	cout << ans << "\n";


	return 0;
}