#include <iostream>

using namespace std;

int N;
int arr[1001];
int is_isc = 0;
int ground;
int max_val = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (i > 0 && arr[i - 1] < arr[i] && is_isc == 0)
		{
			is_isc = 1;
			ground = arr[i - 1];
		}

		if (arr[i - 1] >= arr[i] && is_isc == 1)
		{
			int size = arr[i - 1] - ground;
			max_val = max_val > size ? max_val : size;
			is_isc = 0;
		}

		if (i == N - 1 && is_isc == 1)
		{
			int size = arr[i] - ground;
			max_val = max_val > size ? max_val : size;
		}
	}

	cout << max_val << endl;

	return 0;
}