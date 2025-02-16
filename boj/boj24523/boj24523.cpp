// boj 24523번 내 뒤에 나와 다른 수
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	vector<int> result(N, -1);
	stack<int> st;

	for (int i = N - 1; i >= 0; i--)
	{
		while (!st.empty() && v[st.top()] == v[i])
		{
			st.pop();
		}

		if (!st.empty())
		{
			result[i] = st.top() + 1;
		}

		st.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}