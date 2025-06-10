#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> numbers(M + 1);

	for (int i = 2; i <= M; i++)
	{
		numbers[i] = i;
	}

	for (int i = 2; i <= sqrt(M); i++)
	{
		if (numbers[i] == 0)
			continue;
		for (int j = i * i; j <= M; j += i)
		{
			numbers[j] = 0;
		}
	}

	for (int i = N; i <= M; i++)
	{
		if (numbers[i] == 0)
			continue;
		else
			cout << numbers[i] << "\n";
	}

	return 0;
}