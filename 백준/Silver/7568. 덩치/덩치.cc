#include <iostream>
using namespace std;

int N;
pair<int, int> students[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> students[i].first >> students[i].second;
	}

	for (int i = 0; i < N; i++)
	{
		int k = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (students[i].first < students[j].first && students[i].second < students[j].second)
				k++;
		}
		cout << k + 1 << " ";
	}

	cout << "\n";

	return 0;
}