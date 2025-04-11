#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N, M;

	cin >> N >> M;

	long long ans = N - M > 0 ? N - M : M - N;

	cout << ans << '\n';
	

	return 0;
}