#include <iostream>
#include <deque>
using namespace std;

const int MAX_N = 500000;
int N;
deque<int> dq;

void solve()
{
	while (dq.size() != 1)
	{
		dq.pop_front();
		if (dq.size() == 1)
			break;
		int to_bottom = dq.front();
		dq.pop_front();
		dq.push_back(to_bottom);
	}

	cout << dq.front() << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	solve();

	return 0;
}