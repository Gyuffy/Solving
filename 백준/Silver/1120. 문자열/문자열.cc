#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int min_val = 21e8;

	for (int i = 0; i <= B.length() - A.length(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < A.length(); j++)
		{
			if (A[j] != B[j + i])
				cnt++;
		}

		min_val = min_val < cnt ? min_val : cnt;
	}

	cout << min_val << "\n";

	return 0;
}