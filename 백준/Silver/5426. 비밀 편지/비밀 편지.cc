#include <iostream>
#include <string>
#include <math.h>
using namespace std;

char MAP[100][100];
string msg;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, tc;
	cin >> T;

	for (tc = 1; tc <= T; tc++)
	{
		cin >> msg;
		int len = msg.length();
		int N = sqrt(len);
		int idx = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				MAP[i][j] = msg[idx];
				idx++;
			}
		}

		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				cout << MAP[j][i];
			}
		}

		cout << '\n';
	}

	return 0;
}