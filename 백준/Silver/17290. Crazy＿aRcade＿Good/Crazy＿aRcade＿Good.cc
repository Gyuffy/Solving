#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

char map_data[10][10];
int dist[10][10];
int py, px;
int ans = 0;

bool chkValid(int y, int x)
{
	if (map_data[y][x] == 'o')
		return false;

	for (int i = y + 1; i < 10; i++)
	{
		if (map_data[i][x] == 'o')
			return false;
	}

	for (int i = y - 1; i >= 0; i--)
	{
		if (map_data[i][x] == 'o')
			return false;
	}

	for (int i = x + 1; i < 10; i++)
	{
		if (map_data[y][i] == 'o')
			return false;
	}

	for (int i = x - 1; i >= 0; i--)
	{
		if (map_data[y][i] == 'o')
			return false;
	}

	return true;
}

void bfs(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	dist[sy][sx] = 0;
	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny >= 10 || ny < 0 || nx >= 10 || nx < 0)
				continue;
			if (dist[ny][nx] != -1)
				continue;

			dist[ny][nx] = dist[now.first][now.second] + 1;
			if (chkValid(ny, nx))
			{
				ans = dist[ny][nx];
				return;
			}

			q.push({ ny, nx });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> py >> px;
	px--;
	py--;
	for (int i = 0; i < 10; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < 10; j++)
		{
			map_data[i][j] = row[j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			dist[i][j] = -1;
		}
	}

	if (chkValid(py, px))
	{
		cout << ans << "\n";
		return 0;
	}

	bfs(py, px);

	cout << ans << "\n";

	return 0;
}