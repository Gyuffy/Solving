#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Iceberg
{
	int height;
	int y;
	int x;
};

int N, M;
int MAP[300][300];
int copied_map[300][300];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
vector<Iceberg> ice;
int time_year = 0;
int temp[300][300];
int flag = 0;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			copied_map[i][j] = MAP[i][j];
			if (MAP[i][j] != 0)
				ice.push_back({ MAP[i][j], i, j });
		}
	}
}

void recur(int cy, int cx, int idx)
{
	temp[cy][cx] = -1 * idx;
	for (int d = 0; d < 4; d++)
	{
		int ny = cy + dy[d];
		int nx = cx + dx[d];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (temp[ny][nx] > 0)
			recur(ny, nx, idx);
	}
}

int numbering()
{
	int land = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] > 0)
			{
				recur(i, j, land);
				land++;
			}
		}
	}

	return land - 1;
}

bool allMelt()
{
	for (int i = 0; i < ice.size(); i++)
	{
		if (ice[i].height > 0)
		{
			return false;
		}
	}
	return true;
}

void simulate()
{
	int div = 1;	// 빙산이 총 몇 개로 분할되어 있는가
	while (true)
	{
		// 종료 조건 1 : 빙산이 2개 이상으로 분할되면 종료
		if (div >= 2)
		{
			break;
		}

		// 종료 조건 2 : 빙산이 전부 녹았으면 flag를 1로 만들고 종료
		if (allMelt())
		{
			flag = 1;
			break;
		}

		// 시간이 지남에 따라 빙산이 녹는다.
		time_year++;
		for (int i = 0; i < ice.size(); i++)
		{
			int ocean = 0;
			Iceberg cur = ice[i];

			for (int d = 0; d < 4; d++)
			{
				int ny = cur.y + dy[d];
				int nx = cur.x + dx[d];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (MAP[ny][nx] != 0)
					continue;
				ocean++;
			}

			cur.height -= ocean;
			cur.height = cur.height <= 0 ? 0 : cur.height;


			copied_map[cur.y][cur.x] = cur.height;
			ice[i] = cur;

		}
		memcpy(MAP, copied_map, sizeof(MAP));

		memcpy(temp, MAP, sizeof(temp));
		div = numbering();
	}
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	input();
	simulate();

	if (flag)
		cout << 0 << "\n";
	else
		cout << time_year << "\n";

	return 0;
}