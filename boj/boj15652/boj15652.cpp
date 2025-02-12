#include <iostream>

using namespace std;

int N, M;
int path[8];

void func(int lev, int idx)
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

	for (int i = idx; i <= N; i++)
	{
		path[lev] = i;
		func(lev + 1, i);
	}

}

int main()
{
	cin >> N >> M;

	func(0, 1);


	return 0;
}