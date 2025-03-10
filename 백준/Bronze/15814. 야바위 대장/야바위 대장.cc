#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char S[101];
int T, A, B;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	cin >> T;

	char temp;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		temp = S[A];
		S[A] = S[B];
		S[B] = temp;
	}

	cout << S << "\n";

	return 0;
}