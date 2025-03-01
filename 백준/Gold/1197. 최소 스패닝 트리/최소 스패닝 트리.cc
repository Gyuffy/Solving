#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int a;
	int b;
	int cost;
};

int nodeCnt, edgeCnt;
vector<Edge> v;

int parent[10001];

bool compare(Edge a, Edge b)
{
	return a.cost < b.cost;
}

void init()
{
	for (int i = 1; i <= nodeCnt; i++)
	{
		parent[i] = i;
	}
}

int find(int tar)
{
	if (tar == parent[tar])
		return tar;

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

	for (Edge sel : v)
	{
		int a = sel.a;
		int b = sel.b;
		int cost = sel.cost;

		if (find(a) == find(b))
			continue;
		setUnion(a, b);
		result += cost;
		selectCount++;
		if (selectCount == nodeCnt - 1)
			break;
	}

	return result;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	cin >> nodeCnt >> edgeCnt;
	int a, b, cost;
	for (int i = 0; i < edgeCnt; i++)
	{
		cin >> a >> b >> cost;
		v.push_back({ a, b, cost });
	}

	init();
	sort(v.begin(), v.end(), compare);

	int result = kruskal();

	cout << result << "\n";

	return 0;
}