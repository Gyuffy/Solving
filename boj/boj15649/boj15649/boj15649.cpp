#include <iostream>

using namespace std;

int N, M;
int path[8];
int visited[8];

void func(int lev)
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

	for (int i = 1; i <= N; i++)
	{
		if (visited[i-1] ==1)
		{
			continue;
		}
		path[lev] = i;
		visited[i - 1] = 1;
		func(lev + 1);
		path[lev] = 0;
		visited[i - 1] = 0;
	}

	

}

int main()
{
	cin >> N >> M;

	func(0);

	return 0;
}