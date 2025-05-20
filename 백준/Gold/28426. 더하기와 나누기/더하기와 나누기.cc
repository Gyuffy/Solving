#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N; cin >> N;

    cout << 3 << ' ';
    int cur = 2;
    for (int i = 2; i < N; i++)
    {
        cout << cur << ' ';
        cur += 2;
    }

    if (N > 1)
    {
        if (N % 3 == 2) cur += 4;
        cout << cur;
    }
    cout << '\n';
    return 0;

	return 0;
}