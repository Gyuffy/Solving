#include <iostream>
#include <algorithm>
using namespace std;

int N, progress, cnt, max_val;
int survey_data[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> survey_data[i];
	}
	
	sort(survey_data, survey_data + N);

	do
	{
		for (int i = 0; i < N; i++)
		{
			progress = 0;
			for (int j = i; j <= N; j++)
			{
				if (j == N)
				{
					j = 0;
				}
				progress += survey_data[j];

				if (progress > 50)
				{
					break;
				}
				else if (progress == 50)
				{
					cnt++;
					break;
				}
			}
		}
		max_val = max(max_val, cnt);
		cnt = 0;
	} while (next_permutation(survey_data, survey_data + N));

	int ans = max_val / 2;
	cout << ans << "\n";

	return 0;
}