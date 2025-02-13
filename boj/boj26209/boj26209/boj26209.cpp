#include <iostream>

using namespace std;

int bit[8];

int main()
{
	for (int i = 0; i < 8; i++)
	{
		cin >> bit[i];
	}

	for (int i = 0; i < 8; i++)
	{
		if (bit[i] != 0 && bit[i] != 1)
		{
			cout << "F";
			break;
		}
		else
		{
			if (i == 7)
			{
				cout << "S";
			}
		}
	}

	return 0;
}