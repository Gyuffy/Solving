#include <iostream>

using namespace std;

int N, M;
int path[8];

void func(int lev, int from)
{
	if (lev == M)
	{
		for (int i = 0; i < M; i++)
		{
			if (i == M - 1)
			{
<<<<<<< HEAD
				cout << path[i];3
=======
				cout << path[i];
>>>>>>> 985b541246dd4bc51700f0fcae36b9e02669a82a
			}
			else
			{
				cout << path[i] << " ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = from; i <= N; i++)
	{

		/*if (lev != 0 && path[lev - 1] > i)
		{
			continue;
		}*/
		path[lev] = i;
		func(lev + 1, i + 1);
		path[lev] = -1;
	}
}

int main()
{
	cin >> N >> M;

	func(0, 1);

	return 0;
}