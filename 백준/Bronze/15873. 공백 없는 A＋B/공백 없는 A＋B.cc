#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	string num;

	cin >> num;

	if (num.length() == 2)
	{
		A = num[0] - '0';
		B = num[1] - '0';
	}
	else if (num.length() == 3 && num[0] != 0 + '0')
	{
		A = 10 * (num[0] - '0') + num[1] - '0';
		B = num[2] - '0';

		if (A > 10)
		{
			A = num[0] - '0';
			B = 10 * (num[1] - '0') + num[2] - '0';
		}
	}
	else if (num.length() == 3)
	{
		A = 0;
		B = 10 * (num[1] - '0') + num[2] - '0';
	}
	else if (num.length() == 4)
	{
		A = 10 * (num[0] - '0') + num[1] - '0';
		B = 10 * (num[2] - '0') + num[3] - '0';
	}

	int ans = A + B;
	cout << ans << "\n";

	return 0;
}