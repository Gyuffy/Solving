#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Val
{
	int abs_val;
	int ori_val;
};

struct Compare
{
	bool operator()(Val a, Val b)
	{
		if (a.abs_val == b.abs_val)
			return a.ori_val > b.ori_val;
		return a.abs_val > b.abs_val;
	}
};

int N, tmp;
Val val;
priority_queue<Val, vector<Val>, Compare> pq;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				val = pq.top();
				pq.pop();
				cout << val.ori_val << "\n";
			}
		}
		else
		{
			if (tmp > 0)
			{
				val = { tmp, tmp };
			}
			else
			{
				val = { -1 * tmp, tmp };
			}
			pq.push(val);
		}
	}

	return 0;
}