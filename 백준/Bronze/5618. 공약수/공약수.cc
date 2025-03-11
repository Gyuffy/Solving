#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, min_val;
	int numbers[3];

	min_val = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
		min_val = min_val > numbers[i] ? min_val : numbers[i];
	}

	for (int i = 1; i <= min_val; i++)
	{
		bool pass = true;
		for (int j = 0; j < n; j++)
		{
			if (numbers[j] % i != 0)
			{
				pass = false;
				break;
			}
		}
		if (pass)
		{
			cout << i << "\n";
		}
	}

	return 0;
}