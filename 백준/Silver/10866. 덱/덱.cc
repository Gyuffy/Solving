#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int N;
deque<int> dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("sample_input.txt", "r", stdin);

	string comm;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> comm;
		if (comm == "push_front")
		{
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (comm == "push_back")
		{
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (comm == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (comm == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (comm == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (comm == "empty")
		{
			cout << dq.empty() << '\n';
		}
		else if (comm == "front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << '\n';
			}
			else
				cout << "-1\n";
		}
		else if (comm == "back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << '\n';
			}
			else
				cout << "-1\n";
		}
	}

	return 0;
}