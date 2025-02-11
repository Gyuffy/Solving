// 백준 5568번 카드 놓기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
int cards[10];
int path[4];
int visited[10];

string result;
vector<string> v;

void dfs(int lev)
{
	if (lev == k)
	{
		for (int i = 0; i < k; i++)
		{
			result += to_string(path[i]);
		}

		if (v.size() == 0)
		{
			v.push_back(result);
			result = "";
		}

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == result || result == "")
			{
				result = "";
				break;
			}
			else if (v[i] != result && i == v.size() - 1)
			{
				v.push_back(result);
				result = "";
			}
		}

		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 1)
		{
			continue;
		}
		visited[i] = 1;
		path[lev] = cards[i];
		dfs(lev + 1);
		visited[i] = 0;
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}

	dfs(0);
	cout << v.size();

	return 0;
}