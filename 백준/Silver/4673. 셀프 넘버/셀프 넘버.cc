#include <iostream>

using namespace std;

int numbers[10001];

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		int sum = 0;
		sum += i;
        
        int temp = i;

		while (temp != 0)
		{
			sum += temp % 10;
            temp /= 10;
		}
        
        if (sum <= 10000)
            numbers[sum] = 1;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (!numbers[i])
		{
			cout << i << '\n';
		}
	}

	return 0;
}