#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int N, M, K, X;
int dist[300001];
vector<int> v[300001];

void dijkstra(int st)
{
	priority_queue<int, vector<int>, cmp> pq;
	pq.push(st);
	dist[st] = 0;

	while (!pq.empty())
	{
		int now = pq.top();
		pq.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			int next_cost = dist[now] + 1;

			int tar = v[now][i];

			if (next_cost < dist[tar])
			{
				dist[tar] = next_cost;
				pq.push(tar);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int to, from;

	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
	}

	for (int i = 0; i < 300001; i++)
	{
		dist[i] = 21e8;
	}

	dijkstra(X);

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
		{
			cout << i << "\n";
			cnt++;
		}
	}

	if (cnt == 0)
		cout << "-1\n";

	return 0;
}