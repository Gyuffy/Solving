#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, M;
int to;
int dist[101001];
vector<int> v[101001];

void bfs(int st)
{
	queue<int> q;
	q.push(st);
	dist[st] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == N)
			return;
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (dist[next])
				continue;
			if (next > N)
			{
				dist[next] = dist[now];
			}
			else
			{
				dist[next] = dist[now] + 1;
			}
			q.push(next);
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);
	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> to;
			v[i + N].push_back(to);
			v[to].push_back(i + N);
		}
	}

	bfs(1);

	if (dist[N] == 0)
		cout << "-1\n";
	else
		cout << dist[N] << "\n";

	return 0;
}