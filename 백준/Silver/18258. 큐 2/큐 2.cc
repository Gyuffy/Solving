#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<int> q;
	int N;
	string comm;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> comm;
		if (comm == "push")
		{
			int num;
			cin >> num;
			q.push_back(num);
		}
		else if (comm == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				int num;
				num = q.front();
				q.pop_front();
				cout << num << '\n';
			}
		}
		else if (comm == "size")
		{
			cout << q.size() << '\n';
		}
		else if (comm == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (comm == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if (comm == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
	}


	return 0;
}