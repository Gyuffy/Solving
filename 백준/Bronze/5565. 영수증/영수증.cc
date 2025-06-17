#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int total; cin >> total;
	
	for (int i = 0; i < 9; i++)
	{
		int temp; cin >> temp;
		total -= temp;
	}

	cout << total << "\n";

	return 0;
}