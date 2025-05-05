#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int sdr[100][3];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> sdr[i][0] >> sdr[i][1] >> sdr[i][2];

	int ans = 21e8;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			for (int k = 0; k < N; k++) 
			{
				int max_a = max({ sdr[i][0], sdr[j][0], sdr[k][0] });
				int max_b = max({ sdr[i][1], sdr[j][1], sdr[k][1] });
				int max_c = max({ sdr[i][2], sdr[j][2], sdr[k][2] });

				int cnt = 0;
				for (int m = 0; m < N; m++) 
				{
					if (sdr[m][0] <= max_a && sdr[m][1] <= max_b && sdr[m][2] <= max_c)
						cnt++;
				}

				if (cnt >= K)
					ans = min(ans, max_a + max_b + max_c);
			}
		}
	}

	cout << ans << "\n";
	return 0;
}