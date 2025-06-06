#include <iostream>
#include <vector>

using namespace std;

int n, m;
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

	cin >> n >> m;
	parent.resize(n + 1);

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int query, a, b;
		cin >> query >> a >> b;

		if (query == 0)
		{
			setUnion(a, b);
		}
		else if (query == 1)
		{
			if (find(a) == find(b))
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
			}
		}
	}

	return 0;
}