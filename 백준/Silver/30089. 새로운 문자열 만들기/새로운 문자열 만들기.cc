#include <iostream>
#include <string>
using namespace std;

string add_char(int idx, const string& str)
{
	string res = str;
	for (int i = idx; i >= 0; i--)
	{
		res += str[i];
	}

	return res;
}

string solve(const string& str)
{
	string X = str;
	int X_length = X.length();
	int idx = 0;

	for (int i = 0; i < X_length; i++)
	{
		if (X[i] != X[X_length - (i + 1)])
		{
			X = add_char(idx, str);
			idx++;
			i = 0;
			X_length = X.length();
		}
	}

	return X;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> S;
		string ans = solve(S);
		cout << ans << "\n";
	}

	return 0;
}