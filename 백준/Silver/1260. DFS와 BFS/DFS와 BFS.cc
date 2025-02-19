#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M, V, tmp_st, tmp_en;
int arr[1001][1001];
int visited[1001];

void dfs(int cur)
{
	cout << cur << " ";
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;
		if (arr[cur][i] == 0)
			continue;

		visited[i] = 1;
		dfs(i);
	}
}

void bfs(int st)
{
	queue<int> q;
	visited[st] = 1;
	q.push(st);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 1; i <= N; i++)
		{
			if (visited[i])
				continue;
			if (arr[now][i] == 0)
				continue;
			visited[i] = 1;
			q.push(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		cin >> tmp_st >> tmp_en;
		arr[tmp_st][tmp_en] = 1;
		arr[tmp_en][tmp_st] = 1;
	}

	visited[V] = 1;
	dfs(V);
	cout << "\n";

	for (int i = 1; i <= N; i++)
	{
		visited[i] = 0;
	}

	bfs(V);

	return 0;
}