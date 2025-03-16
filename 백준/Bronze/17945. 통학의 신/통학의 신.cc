#include <iostream>
#include <cmath>
using namespace std;

int A, B, ans1, ans2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;

	A;

	ans1 = (-1 * A) - sqrt(A * A - B);
	ans2 = (-1 * A) + sqrt(A * A - B);

	if (ans1 == ans2)
	{
		cout << ans1 << '\n';
	}
	else
	{
		cout << ans1 << " " << ans2 << '\n';
	}

	return 0;
}