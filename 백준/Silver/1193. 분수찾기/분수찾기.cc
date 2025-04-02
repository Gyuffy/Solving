#include <iostream>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int idx = 1;

	while (N > idx)
	{
		N -= idx;
		idx++;
	}

	if (idx % 2 == 0)
	{
		cout << N << '/' << idx - N + 1 << '\n';
	}
	else
	{
		cout << idx - N + 1 << '/' << N << '\n';
	}

	return 0;
}