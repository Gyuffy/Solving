#include <iostream>
using namespace std;

int W, H;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> W >> H;
	float ans = (float)(W * H) / 2;
	cout.precision(1);
	cout << fixed;
	cout << ans << "\n";

	return 0;
}