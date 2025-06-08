#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> parent;
int N, M;

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
	parent.resize(N);

	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int info;
			cin >> info;

			if (info == 1)
			{
				setUnion(i, j);
			}
		}
	}

	vector<int> city(M);
	for (int i = 0; i < M; i++)
	{
		cin >> city[i];
		city[i]--;
	}

	int firstCity = find(city[0]);
	string ans = "YES\n";

	for (int i = 1; i < M; i++)
	{
		if (firstCity != find(city[i]))
		{
			ans = "NO\n";
			break;
		}
	}

	cout << ans;

	return 0;
}