#define _CRT_SECURE_NO_WARNINGS
#define N_MAX 100001
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, X, from, to, high, low;
int U, V;
int visited[N_MAX];
vector<int> ranking[N_MAX];
vector<int> revRank[N_MAX];

void input()
{
	high = 0;
	low = 0;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		ranking[from].push_back(to);
		revRank[to].push_back(from);
	}
}

void searchLow(int cur)
{
	for (int i = 0; i < ranking[cur].size(); i++)
	{
		int next = ranking[cur][i];
		if (visited[next])
			continue;
		visited[next] = 1;
		low++;
		searchLow(next);
	}
}

void searchHigh(int cur)
{
	for (int i = 0; i < revRank[cur].size(); i++)
	{
		int next = revRank[cur][i];
		if (visited[next])
			continue;
		visited[next] = 1;
		high++;
		searchHigh(next);
	}
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	input();

	// DFS를 통해 자기보다 낮은 순위에 있는 사람을 카운트
	searchLow(X);
	
	// 반대로 탐색하여 높은 순위 인원을 카운트
	memset(visited, 0, sizeof(visited));
	searchHigh(X);

	U = high + 1;
	V = N - low;
	cout << U << "\n" << V << "\n";

	return 0;
}