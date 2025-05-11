#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NM = 8;

int N, M;
int numbers[MAX_NM];
int path[MAX_NM];
int visited[MAX_NM];

void recur(int lev)
{
	if (lev == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		path[lev] = numbers[i];
		recur(lev + 1);
		visited[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	sort(numbers, numbers + N);

	recur(0);

	return 0;
}