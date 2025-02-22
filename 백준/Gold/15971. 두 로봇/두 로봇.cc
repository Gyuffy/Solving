#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
	int to;
	int cost;
};

int N, st_a, st_b;
int from, to, cost;
int min_dist = 21e8;
int max_dist = 0;
int visited[100001];
vector<Edge> way[100001];

void input()
{
	cin >> N >> st_a >> st_b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> from >> to >> cost;
		way[from].push_back({ to, cost });
		way[to].push_back({ from, cost });
	}
}

void dfs(int cur, int dist, int max_val)
{
	if (cur == st_b)
	{
		if (min_dist > dist)
			min_dist = dist;
		if (max_dist < max_val)
			max_dist = max_val;
		return;
	}

	for (int i = 0; i < way[cur].size(); i++)
	{
		int next = way[cur][i].to;
		if (visited[next] == 1)
			continue;
		visited[next] = 1;
		dfs(next, dist + way[cur][i].cost, max_val > way[cur][i].cost ? max_val : way[cur][i].cost);
		visited[next] = 0;
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);
	input();
	if (st_a == st_b || N == 1)
	{
		min_dist = max_dist;
	}
	else
	{
		dfs(st_a, 0, 0);
	}
	min_dist = min_dist - max_dist;

	cout << min_dist << "\n";

	return 0;
}