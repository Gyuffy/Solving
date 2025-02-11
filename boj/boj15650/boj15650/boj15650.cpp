#include <iostream>

using namespace std;

int N, M;
int path[8];
int visited[8];

void func(int lev, int from)
{
	if (lev == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = from; i <= N; i++)
	{
		if (visited[i] == 1)
		{
			continue;
		}
		/*if (lev != 0 && path[lev - 1] > i)
		{
			continue;
		}*/
		visited[i] = 1;
		path[lev] = i;
		func(lev + 1, i + 1);
		path[lev] = -1;
		visited[i] = 0;
	}
}

int main()
{
	cin >> N >> M;

	func(0, 1);

	return 0;
}