#include <iostream>
#include <cmath>
using namespace std;

int pos[4][2];

double get_dist(int* a, int* b)
{
	int x = a[0] - b[0];
	int y = a[1] - b[1];

	return sqrt(x * x + y * y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> pos[i][j];
		}
	}

	double min_dist = 21e8;
	double sum = 0;

	// 1 2 3
	sum += get_dist(pos[0], pos[1]);
	sum += get_dist(pos[1], pos[2]);
	sum += get_dist(pos[2], pos[3]);
	min_dist = min_dist < sum ? min_dist : sum;
	sum = 0;

	// 1 3 2
	sum += get_dist(pos[0], pos[1]);
	sum += get_dist(pos[1], pos[3]);
	sum += get_dist(pos[3], pos[2]);
	min_dist = min_dist < sum ? min_dist : sum;
	sum = 0;

	// 2 1 3
	sum += get_dist(pos[0], pos[2]);
	sum += get_dist(pos[2], pos[1]);
	sum += get_dist(pos[1], pos[3]);
	min_dist = min_dist < sum ? min_dist : sum;
	sum = 0;

	// 2 3 1
	sum += get_dist(pos[0], pos[2]);
	sum += get_dist(pos[2], pos[3]);
	sum += get_dist(pos[3], pos[1]);
	min_dist = min_dist < sum ? min_dist : sum;
	sum = 0;

	// 3 1 2
	sum += get_dist(pos[0], pos[3]);
	sum += get_dist(pos[3], pos[1]);
	sum += get_dist(pos[1], pos[2]);
	min_dist = min_dist < sum ? min_dist : sum;
	sum = 0;

	// 3 2 1
	sum += get_dist(pos[0], pos[3]);
	sum += get_dist(pos[3], pos[2]);
	sum += get_dist(pos[2], pos[1]);
	min_dist = min_dist < sum ? min_dist : sum;
	sum = 0;

	int ans = min_dist;
	
	cout << ans << "\n";

	return 0;
}