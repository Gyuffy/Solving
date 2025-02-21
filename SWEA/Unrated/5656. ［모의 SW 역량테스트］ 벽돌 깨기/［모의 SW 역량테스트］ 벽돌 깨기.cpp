#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	int r;
	int c;
};

struct Brick
{
	int range;
	int r;
	int c;
};

int N, W, H;
int MAP[15][12];
int origin[15][12];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int path[4];
int visited[15][12];
int score = 0;
int max_val = 0;
int brick_cnt = 0;
int pass = 1;

void init()
{
	memset(path, -1, sizeof(path));
	max_val = 0;
	score = 0;
	pass = 1;
}

void input()
{
	cin >> N >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> MAP[i][j];
			origin[i][j] = MAP[i][j];
			if (MAP[i][j] == 1)
				pass = 0;
		}
	}
}

void bfs(Point st)
{
	queue<Point> q;
	q.push(st);
	visited[st.r][st.c] = 1;

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		int range = MAP[cur.r][cur.c];
		MAP[cur.r][cur.c] = 0;

		for (int i = 1; i < range; i++)
		{
			for (int d = 0; d < 4; d++)
			{
				Point next;
				next.r = cur.r + dr[d] * i;
				next.c = cur.c + dc[d] * i;

				if (next.r < 0 || next.c < 0 || next.r >= H || next.c >= W)
					continue;
				if (visited[next.r][next.c])
					continue;

				visited[next.r][next.c] = 1;
				q.push(next);
			}
		}

	}
}

void gravity()
{
	Point ground;
	for (int i = 0; i < W; i++)
	{
		bool isZero = false;
		for (int j = H - 1; j >= 0; j--)
		{
			if (MAP[j][i] == 0 && !isZero)
			{
				isZero = true;
				ground = { j, i };
			}
			if (isZero && MAP[j][i] != 0)
			{
				MAP[ground.r][ground.c] = MAP[j][i];
				MAP[j][i] = 0;
				ground.r--;
			}
		}
	}
}

void simulate()
{
	Point tar;
	int shoot;

	for (int i = 0; i < N; i++)
	{
		shoot = path[i];
		for (int j = 0; j < H; j++)
		{
			if (MAP[j][shoot] != 0)
			{
				tar = { j, shoot };
				break;
			}
			else if (j == H - 1)
			{
				return;
			}
		}

		bfs(tar);
		gravity();
		memset(visited, 0, sizeof(visited));
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (MAP[i][j] == 0)
				score++;
		}
	}

	max_val = max(max_val, score);
	score = 0;
}

void reArray()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			MAP[i][j] = origin[i][j];
		}
	}
}

void dfs(int lev)
{
	// dfs 종료 조건
	if (lev == N)
	{
		simulate();
		reArray();
		return;
	}

	for (int i = 0; i < W; i++)
	{
		path[lev] = i;
		dfs(lev + 1);
		path[lev] = -1;
	}
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	int T, test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		if (pass)
		{
			cout << "#" << test_case << " " << 0 << "\n";
			continue;
		}
		dfs(0);
		cout << "#" << test_case << " " << W * H - max_val << "\n";
	}


	return 0;
}