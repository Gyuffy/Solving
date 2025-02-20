#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
	int y;
	int x;
};

struct Edge
{
	int from;
	int to;
	int cost;
};

int N, M;
int MAP[10][10];
int visited[10][10];
int dist[10][10];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int nodeCnt, edgeCnt;
int parent[6];
int pass = 0;

vector<Point> islands[7];
vector<Edge> edges;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j])
			{
				MAP[i][j] = -1;
			}
		}
	}
}

void recur(Point ckpt, int idx)
{
	int ny, nx;

	MAP[ckpt.y][ckpt.x] = idx;

	for (int i = 0; i < 4; i++)
	{
		ny = ckpt.y + dy[i];
		nx = ckpt.x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (MAP[ny][nx] == -1)
		{
			recur({ ny, nx }, idx);
		}
	}
}

void numbering()
{
	int idx = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == -1)
			{
				recur({ i, j }, idx);
				idx++;
			}
		}
	}
	nodeCnt = idx - 1;
}

void createLands()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] != 0)
			{
				int idx = MAP[i][j];
				islands[idx].push_back({ i, j });
			}
		}
	}
}

void bfs(Point st, int min_val, int move_dir)
{
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;
	dist[st.y][st.x] = 0;

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		int ny = cur.y + dy[move_dir];
		int nx = cur.x + dx[move_dir];
		if (visited[ny][nx])
			continue;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (MAP[ny][nx] != 0 && dist[cur.y][cur.x] == 1)
			continue;
		if (MAP[ny][nx] == MAP[st.y][st.x])
			continue;
		if (MAP[ny][nx] != 0 && dist[cur.y][cur.x] < min_val)
		{
			int from = MAP[st.y][st.x];
			int to = MAP[ny][nx];
			int cost = dist[cur.y][cur.x];
			edges.push_back({ from, to, cost });
			min_val = cost;
		}

		visited[ny][nx] = 1;
		dist[ny][nx] = dist[cur.y][cur.x] + 1;
		q.push({ ny, nx });
	}
}

bool compare(Edge a, Edge b)
{
	return a.cost < b.cost;
}

int find(int tar)
{
	if (tar == parent[tar])
		return tar;

	// Path Compression
	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return;

	parent[t2] = t1;
}

int kruskal()
{
	int result = 0;

	int selectCount = 0;

	for (Edge sel : edges)
	{
		int a = sel.from;
		int b = sel.to;
		int cost = sel.cost;
		if (find(a) == find(b))
			continue;
		setUnion(a, b);
		result += cost;
		selectCount++;
		if (selectCount == nodeCnt - 1)
		{
			pass = 1;
			break;
		}
	}
	return result;
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


int main()
{
	// freopen("sample_input.txt", "r", stdin);
	input();
	numbering();
	createLands();

	for (int i = 1; i < 7; i++)
	{
		int length = 21e8;
		for (int j = 0; j < islands[i].size(); j++)
		{
			for (int k = 0; k < 4; k++)
			{
				bfs(islands[i][j], length, k);
				initArr();
			}
		}
	}

	sort(edges.begin(), edges.end(), compare);
	
	for (int i = 1; i < edges.size(); i++)
	{
		if (edges[i].from == edges[i - 1].from && edges[i].to == edges[i - 1].to)
		{
			edges.erase(edges.begin() + i);
		}
	}

	// MST : Kruskal 알고리즘 구현
	for (int i = 0; i < 6; i++)
		parent[i] = i;

	int result = kruskal();

	if (pass)
		cout << result << "\n";
	else
		cout << "-1\n";


	return 0;
}