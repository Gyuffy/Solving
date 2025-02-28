#include <iostream>

using namespace std;

long long n;
long long fibonacci[91];

int main()
{
	cin >> n;

	if (n == 0)
	{
		cout << 0 << "\n";
		return 0;
	}
	else if (n == 1)
	{
		cout << 1 << "\n";
		return 0;
	}

	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	cout << fibonacci[n] << "\n";


	return 0;
}