#include <iostream>

using namespace std;

int N;
int arr[100][100];

void floyd_warshall()
{
	// k = 거쳐가는 노드
	for (int k = 0; k < N; k++)
	{
		// i = 출발 노드
		for (int i = 0; i < N; i++)
		{
			// j = 도착 노드
			for (int j = 0; j < N; j++)
			{
				if (arr[i][k] && arr[k][j])
				{
					arr[i][j] = 1;
				}
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	floyd_warshall();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}