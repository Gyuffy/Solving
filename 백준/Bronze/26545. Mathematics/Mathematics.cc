#include <iostream>

using namespace std;

int n, a;
int sum;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
	}

	cout << sum;

	return 0;
}