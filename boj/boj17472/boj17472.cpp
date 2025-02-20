#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
	int y, x;
};

struct Edge
{
	int from;
	int to;
	int cost;
};

vector<Point> lands;
vector<Point> v[6];
vector<int> idxVec;
vector<Edge> edge;

int N, M;
int MAP[10][10];
int islands[100];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int DAT[100];
int dist[10][10];
int visited[10][10];
int min_val[6];

int parent[6];
int nodeCnt, edgeCnt;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
			{
				MAP[i][j] = -1;
				lands.push_back({ i, j });
			}
		}
	}
}

bool isOne(Point a, Point b)
{
	if (a.y == 7 && a.x == 0)
	{
		int de = 1;
	}
	int tmp = abs(b.y - a.y) + abs(b.x - a.x);
	if (tmp > 1)
		return false;
	else
		return true;
}

int find(int tar)
{
	if (tar == islands[tar])
		return tar;

	int ret = find(islands[tar]);
	islands[tar] = ret;
	return ret;
}

void setUnion(int a, int b)
{
	if (a == 16)
	{
		int de = 1;
	}

	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return;

	islands[t2] = t1;
}

void bfs(Point st, int move_dir)
{
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;
	dist[st.y][st.x] = 0;

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		if (MAP[now.y][now.x] != 0 && MAP[now.y][now.x] != MAP[st.y][st.x])
		{
			if (dist[now.y][now.x] - 1 < min_val[MAP[now.y][now.x] - 1])
			{
				edge.push_back({ MAP[st.y][st.x] - 1, MAP[now.y][now.x] - 1, dist[now.y][now.x] - 1 });
				min_val[MAP[now.y][now.x] - 1] = dist[now.y][now.x];
			}
		}


		int ny = now.y + dy[move_dir];
		int nx = now.x + dx[move_dir];
		if (visited[ny][nx])
			continue;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (MAP[ny][nx] != 0 && (MAP[now.y][now.x] == MAP[ny][nx]))
			continue;
		if (MAP[ny][nx] != 0 && dist[now.y][now.x] == 1)
			continue;

		visited[ny][nx] = 1;
		dist[ny][nx] = dist[now.y][now.x] + 1;
		q.push({ ny, nx });

	}
}

void initArr()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 0;
			dist[i][j] = 0;
		}
	}
}

bool compare(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int findd(int tar)
{
	if (tar == parent[tar])
		return tar;

	// Path Compression
	int ret = findd(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnionn(int a, int b)
{
	int t1 = findd(a);
	int t2 = findd(b);

	if (t1 == t2)
		return;

	parent[t2] = t1;
}

int kruskal()
{
	int res = 0;
	int selectCount = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		Edge sel = edge[i];
		int a = sel.from;
		int b = sel.to;
		int cost = sel.cost;

		if (findd(a) == findd(b))
			continue;
		setUnionn(a, b);
		res += cost;
		selectCount++;
		if (selectCount == idxVec.size() - 1)
			break;
	}

	return res;
}

int main()
{
	freopen("sample_input.txt", "r", stdin);
	input();

	// 각 islands의 값을 인덱스로 초기화
	for (int i = 0; i < 100; i++)
	{
		islands[i] = i;
	}

	for (int i = 0; i < lands.size(); i++)
	{
		for (int j = i + 1; j < lands.size(); j++)
		{
			if (isOne(lands[i], lands[j]))
			{
				setUnion(i, j);
			}
		}
	}

	for (int i = 0; i < lands.size(); i++)
	{
		if (DAT[islands[i]] < 1)
		{
			idxVec.push_back(islands[i]);
		}
		DAT[islands[i]]++;
	}

	for (int i = 0; i < idxVec.size(); i++)
	{
		for (int j = 0; j < lands.size(); j++)
		{
			if (islands[j] == idxVec[i])
			{
				v[i].push_back(lands[j]);
				MAP[lands[j].y][lands[j].x] = i + 1;
			}
		}
	}

	for (int island_idx = 0; island_idx < idxVec.size(); island_idx++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			for (int i = 0; i < 6; i++)
			{
				min_val[i] = 21e8;
			}
			for (int k = 0; k < 4; k++)
			{
				bfs({ v[island_idx][j].y, v[island_idx][j].x }, k);
				initArr();
			}
		}
	}
	
	for (int i = 1; i < edge.size(); i++)
	{
		if (edge[i].from == edge[i - 1].from && edge[i].to == edge[i - 1].to)
		{
			edge[i].cost = 10000;
		}
	}
	
	sort(edge.begin(), edge.end(), compare);

	for (int i = 1; i < edge.size(); i++)
	{
		if (edge[i].from == edge[i - 1].from && edge[i].to == edge[i - 1].to)
		{
			edge[i].cost = 10000;
		}
	}

	sort(edge.begin(), edge.end(), compare);

	for (int i = 0; i < 6; i++)
	{
		parent[i] = i;
	}

	int result = kruskal();

	if (result == 0)
		result = -1;

	cout << result << "\n";

	return 0;
}