#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int s1, s2, s3;
	int dat[81] = { 0, };
	pair<int, int> max_val = { 0, 0 };

	cin >> s1 >> s2 >> s3;

	for (int i = 1; i <= s1; i++)
	{
		for (int j = 1; j <= s2; j++)
		{
			for (int k = 1; k <= s3; k++)
			{
				int sum = i + j + k;
				dat[sum]++;
				if (max_val.second < dat[sum])
				{
					max_val = { sum, dat[sum] };
				}
				else if (max_val.second == dat[sum] && max_val.first > sum)
				{
					max_val.first = sum;
				}
			}
		}
	}

	cout << max_val.first << '\n';


	return 0;
}