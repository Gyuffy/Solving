#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int n, m;

// 최종적으로 사용할 인접 리스트
vector<vector<int>> v;
// 변호 여부
vector<int> visited;

bool dfs(int now, int prv)
{
	bool is_cycle = false;

	if (visited[now] == 1)
		return true;

	visited[now] = 1;

	for (int nxt : v[now])
	{
		if (nxt == prv) 
			continue;
		if (dfs(nxt, now))
			is_cycle = true;
	}


	return is_cycle;
}

string checkCycle()
{
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 1)
			continue;
		if (v[i].empty() || !dfs(i, 0))
			return "NO";
	}

	return "YES";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	// 초기의 인접 리스트
	vector<set<int>> init_v(n + 1);

	// visited 배열 초기화 및 크기 할당
	visited.assign(n + 1, 0);
	
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		init_v[from].insert(to);
	}

	// 양방향 관계 벡터를 수집 - SET를 이용
	vector<pair<int, int>> two_way;
	for (int i = 1; i <= n; i++)
	{
		for (int j : init_v[i])
		{
			if (init_v[j].find(i) == init_v[j].end())
				visited[j] = 1;
			else
			{
				if (i > j)
					two_way.push_back({ i, j });
			}
		}
	}

	vector<vector<int>> copy_v(n + 1);
	for (auto &p : two_way)
	{
		int a = p.first;
		int b = p.second;

		if (visited[a] + visited[b] == 2)
			continue;
		else if (visited[a] + visited[b] == 1)
		{
			visited[a] = 1;
			visited[b] = 1;
		}
		else
		{
			copy_v[a].push_back(b);
			copy_v[b].push_back(a);
		}
	}

	v = copy_v;
	string ans = checkCycle();

	cout << ans << '\n';

	return 0;
}