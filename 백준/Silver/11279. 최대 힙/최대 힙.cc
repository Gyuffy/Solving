#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0 && pq.empty())
		{
			cout << 0 << "\n";
		}
		else if (temp == 0 && !pq.empty())
		{
			int ans = pq.top();
			pq.pop();
			cout << ans << "\n";
		}
		else
		{
			pq.push(temp);
		}
	}

	return 0;
}