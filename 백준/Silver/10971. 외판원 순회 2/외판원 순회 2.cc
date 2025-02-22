#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, min_cost;
int arr[16][16];
int visited[16];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void dfs(int from, int cost, int lev)
{
	if (from == 0 && lev == N)
	{
		min_cost = min(min_cost, cost);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[from][i] == 0)
			continue;
		if (visited[i] == 1)
			continue;
		if (cost >= min_cost)
			continue;
		visited[i] = 1;
		cost += arr[from][i];
		dfs(i, cost, lev + 1);
		visited[i] = 0;
		cost -= arr[from][i];
	}
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	input();
	min_cost = 21e8;
	dfs(0, 0, 0);
	cout << min_cost << "\n";

	return 0;
}