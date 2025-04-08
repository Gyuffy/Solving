#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int MAP[500][500];
int visited[500][500];
int max_val = 0;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void dfs(int r, int c, int lev, int sum)
{
	if (lev == 4)
	{
		max_val = max_val > sum ? max_val : sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
		
		visited[nr][nc] = 1;
		sum += MAP[nr][nc];

		dfs(nr, nc, lev + 1, sum);

		visited[nr][nc] = 0;
		sum -= MAP[nr][nc];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 1;
			dfs(i, j, 0, 0);
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int cnt = 0;
			int sum = MAP[i][j];
			int min_val = 21e8;

			for (int d = 0; d < 4; d++)
			{
				int nr = i + dr[d];
				int nc = j + dc[d];

				if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				
				cnt++;
				sum += MAP[nr][nc];
				min_val = min_val < MAP[nr][nc] ? min_val : MAP[nr][nc];
			}

			if (cnt == 4)
				sum -= min_val;
			max_val = max_val > sum ? max_val : sum;
		}
	}

	cout << max_val << '\n';

	return 0;
}