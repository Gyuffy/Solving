#include <iostream>
using namespace std;

int N;
int flw[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> flw[i];
	}

	int max_val = 0;

	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += flw[i];
	}

	int mul = 1;
	for (int i = 3; i < N; i++)
	{
		mul *= flw[i];
	}

	sum += mul;

	max_val = max_val > sum ? max_val : sum;
	sum = 0;
	mul = 1;

	sum += flw[0];
	sum += flw[N - 1];
	sum += flw[N - 2];
	for (int i = 1; i < N-2; i++)
	{
		mul *= flw[i];
	}

	sum += mul;

	max_val = max_val > sum ? max_val : sum;
	sum = 0;
	mul = 1;

	sum += flw[0];
	sum += flw[1];
	sum += flw[N - 1];
	for (int i = 2; i < N - 1; i++)
	{
		mul *= flw[i];
	}

	sum += mul;

	max_val = max_val > sum ? max_val : sum;
	sum = 0;
	mul = 1;

	for (int i = 1; i < N - 3; i++)
	{
		mul *= flw[i];
	}

	sum += mul;
	sum += flw[N - 3];
	sum += flw[N - 2];
	sum += flw[N - 1];

	max_val = max_val > sum ? max_val : sum;
	sum = 0;
	mul = 1;

	cout << max_val << "\n";

	return 0;
}