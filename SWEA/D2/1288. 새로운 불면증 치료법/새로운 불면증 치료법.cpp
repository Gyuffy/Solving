#include <iostream>
#include <bitset>
using namespace std;

int ans;
int k = 1;
int N;
int kN;
bitset<10> bit;

void input()
{
	k = 0;
	bit.reset();
	cin >> N;
}

void solve()
{
	while (!bit.all())
	{
		k++;
		kN = k * N;

		int tmp = kN;
		while (tmp != 0)
		{
			int disit = tmp % 10;
			bit[disit] = 1;
			tmp /= 10;
		}
	}

	ans = kN;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}