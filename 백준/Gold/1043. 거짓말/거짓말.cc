#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	parent.resize(N + 1);

	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	int know;
	cin >> know;
	for (int i = 0; i < know; i++)
	{
		int tmp;
		cin >> tmp;
		setUnion(0, tmp);
	}

	int ans = 0;
	vector<vector<int>> party(M);

	for (int i = 0; i < M; i++)
	{
		int member;
		cin >> member;
		party[i].resize(member);
		for (int j = 0; j < member; j++)
		{
			cin >> party[i][j];
		}

		int firstIdx = party[i][0];
		for (int j = 1; j < member; j++)
		{
			setUnion(firstIdx, party[i][j]);
		}
	}

	for (int i = 0; i < M; i++)
	{
		bool over = true;
		for (int j = 0; j < party[i].size(); j++)
		{
			if (find(party[i][j]) == find(0))
			{
				over = false;
				break;
			}
		}

		if (over)
			ans++;
	}
	
	cout << ans << "\n";


	return 0;
}