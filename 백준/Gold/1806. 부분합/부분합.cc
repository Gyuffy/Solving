#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000001;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0, end = 0;
	int sum = 0;
	int minLen = INF;

	while (end <= N)
	{
		if (sum >= S)
		{
			minLen = min(minLen, end - start);
			sum -= arr[start++];
		}
		else if (end == N)
		{
			break;
		}
		else
		{
			sum += arr[end++];
		}
	}

	if (minLen == INF)
		cout << 0 << "\n";
	else
		cout << minLen << "\n";

	return 0;
}