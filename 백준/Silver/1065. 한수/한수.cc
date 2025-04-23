#include <iostream>
#include <queue>
using namespace std;

int N, cnt;

bool chkValid(int num)
{
	int temp = num;
	queue<int> q;
	while (temp != 0)
	{
		int digit = temp % 10;
		q.push(digit);
		temp /= 10;
	}

	int diff;
	int prev = q.front();
	q.pop();
	if(!q.empty())
		diff = prev - q.front();
	else
	{
		return true;
	}
	for (int i = 0; i < q.size(); i++)
	{
		int now = q.front();
		q.pop();

		if (!q.empty())
		{
			int nxt = q.front();
			int d = now - nxt;
			if (d != diff)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (chkValid(i))
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}