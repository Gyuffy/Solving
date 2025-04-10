#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, V;

	cin >> A >> B >> V;

	int n = A - B;
	V -= A;

	int ans = V / n + 1;
	if (V % n) ans += 1;

	cout << ans << '\n';
	

	return 0;
}