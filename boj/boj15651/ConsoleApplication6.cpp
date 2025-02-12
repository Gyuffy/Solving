#include <iostream>

using namespace std;

int N, M;
int path[8];

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
		path[lev] = i;
		func(lev + 1);
	}

}

int main()
{
	cin >> N >> M;

	func(0);


	return 0;
}