#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
map<int, int> cnt_map;
int cnt = 0;

void inputQ(int N)
{
	max_heap.push(N);
	min_heap.push(N);
	cnt_map[N]++;
	cnt++;
}

void deleteQ(int N)
{
	if (!cnt)
	{
		return;
	}

	if (N == 1)
	{
		int now;

		do
		{
			now = max_heap.top();
			max_heap.pop();
		} while (cnt_map[now] == 0);

		cnt_map[now]--;
		cnt--;
	}
	else if (N == -1)
	{
		int now;
		do
		{
			now = min_heap.top();
			min_heap.pop();
		} while (cnt_map[now] == 0);
		
		cnt_map[now]--;
		cnt--;
	}
}

void print()
{
	int max_val;
	int min_val;

	if (!cnt)
	{
		cout << "EMPTY\n";
		return;
	}

	do
	{
		max_val = max_heap.top();
		max_heap.pop();
	} while (cnt_map[max_val] == 0);

	do
	{
		min_val = min_heap.top();
		min_heap.pop();
	} while (cnt_map[min_val] == 0);

	cout << max_val << ' ' << min_val << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, tc, k, n;
	char comm;

	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		while (!max_heap.empty())
			max_heap.pop();
		while (!min_heap.empty())
			min_heap.pop();
		cnt_map.clear();

		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> comm >> n;
			if (comm == 'I')
				inputQ(n);
			else if (comm == 'D')
				deleteQ(n);
		}

		print();
	}

	return 0;
}