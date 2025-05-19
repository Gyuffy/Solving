#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<vector<int>> points(N, vector<int>(2));

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j >= 0; j--)
		{
			cin >> points[i][j];
		}
	}

	sort(points.begin(), points.end());

	for (int i = 0; i < N; i++)
	{
		cout << points[i][1] << " " << points[i][0] << "\n";
	}

	return 0;
}