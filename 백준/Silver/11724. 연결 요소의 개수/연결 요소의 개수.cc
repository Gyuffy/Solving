#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int nodeCnt, edgeCnt;
int idx = 0;
bool visited[1001];
vector<int> myVec[1001];

void recur(int st)
{
	visited[st] = true;

	for (int i = 0; i < myVec[st].size(); i++)
	{
		int next = myVec[st][i];
		if (visited[next])
			continue;

		recur(next);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	cin >> nodeCnt >> edgeCnt;
	int u, v;
	for (int i = 0; i < edgeCnt; i++)
	{
		cin >> u >> v;
		myVec[u].push_back(v);
		myVec[v].push_back(u);
	}

	for (int i = 1; i <= nodeCnt; i++)
	{
		if (!visited[i])
		{
			idx++;
			recur(i);
		}
	}

	cout << idx << "\n";

	return 0;
}