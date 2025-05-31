#include <iostream>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int mapData[50][50];
int N, M, p;
int my, mx;
int visited[50][50];
int maxScore = 0;

void dfs(int cy, int cx, int cp, int cd, int sum)
{
	bool moved = false;

	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (cd != -1 && cd != i && cp < 2)
			continue;
		if (visited[ny][nx] == 1)
			continue;

		int cost = (cd != -1 && cd != i) ? 2 : 1;
		if (cp - cost < 0)
			continue;

		moved = true;
		visited[ny][nx] = 1;
		dfs(ny, nx, cp - cost, i, sum + mapData[ny][nx]);
		visited[ny][nx] = 0;
	}

	if (!moved)
	{
		maxScore = max(maxScore, sum);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> mapData[i][j];

	cin >> my >> mx >> p;

	visited[my][mx] = 1;
	dfs(my, mx, p, -1, mapData[my][mx]);

	cout << maxScore << "\n";
	return 0;
}

