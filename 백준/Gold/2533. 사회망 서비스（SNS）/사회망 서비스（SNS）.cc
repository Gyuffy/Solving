#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, from, to, ans, cnt;
int maxIdx;
int visited[1000000];
vector<int> edge[1000000];

void input()
{
	cnt = 0;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}
}

bool dfs(int st)
{
	bool flag = false;
	for (int i = 0; i < edge[st].size(); i++)
	{
		int next = edge[st][i];
		if (visited[next] == 1)
			continue;
		visited[next] = 1;
		if (!dfs(next))
		{
			flag = true;
		}
	}

	if (flag)
	{
		cnt++;
		return true;
	}


	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	input();

	if (N == 2)
	{
		cout << "1\n";
		return 0;
	}

	visited[1] = 1;
	dfs(1);

	cout << cnt << "\n";

	return 0;
}