#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int N;
int arr[1000000];
priority_queue<int, vector<int>, greater<int>> pq;
map<int, int> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		pq.push(arr[i]);
		m.insert({ arr[i], -1 });
	}

	int pos = 0;

	while (!pq.empty())
	{
		int now = pq.top();
		pq.pop();

		if (m[now] != -1)
			continue;

		m[now] = pos;
		pos++;
	}

	for (int i = 0; i < N; i++)
	{
		cout << m[arr[i]] << ' ';
	}

	return 0;
}