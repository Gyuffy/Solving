// BFS의 탑 3번 코스타그램
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, to, from, coco, cnt;
vector<int> v[100001];
int visited[100001];

void bfs(int st)
{
	queue<int> q;
	q.push(st);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (visited[next])
				continue;
			visited[next] = 1;
			q.push(next);
			cnt++;
		}
	}
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	cin >> coco;
	cnt = 0;

	bfs(coco);
	cout << cnt - 1 << "\n";

	return 0;
}