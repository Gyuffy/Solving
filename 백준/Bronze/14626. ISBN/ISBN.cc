#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string isbn;
	cin >> isbn;

	int sum = 0;
	int chkW;
	for (int i = 0; i < 13; i++)
	{
		int w = i % 2 == 0 ? 1 : 3;
		if (isbn[i] == '*')
		{
			chkW = w;
		}
		else
		{
			int tmp = isbn[i] - '0';
			sum += w * tmp;
		}
	}

	int ans;
	for (int i = 0; i <= 9; i++)
	{
		int tmp = chkW * i + sum;
		if (tmp % 10 == 0)
		{
			ans = i;
			break;
		}
	}

	cout << ans << "\n";


	return 0;
}