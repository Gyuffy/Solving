#include <iostream>
#include <string>
using namespace std;

bool isValid(int num, int len)
{
	string snum = to_string(num);
	while (len != snum.length())
	{
		snum = '0' + snum;
	}

	for (int i = 0; i < snum.length() / 2; i++)
	{
		if (snum[i] != snum[snum.length() - i - 1])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		string snum;
		cin >> snum;

		if (snum == "0")
			return 0;

		int len = snum.length();
		int num = stoi(snum);

		int cnt = 0;
		while (true)
		{
			if (isValid(num, len))
			{
				break;
			}
			cnt++;
			num++;
		}

		cout << cnt << "\n";
	}
	

	return 0;
}