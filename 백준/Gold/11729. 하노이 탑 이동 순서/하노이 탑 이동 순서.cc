#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, K;
int path[20];

void recur(int from, int via, int to, int n)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
	}
	else
	{
		recur(from, to, via, n - 1);
		cout << from << " " << to << "\n";
		recur(via, from, to, n - 1);
	}

}

int main()
{
	cin >> N;
	
	K = 1;
	int tmp = N;
	while (--tmp)
	{
		K = K * 2 + 1;
	}
	cout << K << "\n";

	recur(1, 2, 3, N);

	return 0;
}