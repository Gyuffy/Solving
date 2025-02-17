#include <iostream>
#include <algorithm>

using namespace std;

struct Parking_time
{
	int arv;
	int lve;
}park[3];

int A, B, C;
int first_arv, final_lve;

int main()
{
	first_arv = 101;
	final_lve = 0;
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++)
	{
		cin >> park[i].arv >> park[i].lve;
		first_arv = min(park[i].arv, first_arv);
		final_lve = max(park[i].lve, final_lve);
	}

	int cnt = 0;
	int pay = 0;
	for (int i = first_arv; i <= final_lve; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (park[j].arv < i && park[j].lve >= i)
			{
				cnt++;
			}
		}
		if (cnt == 1)
		{
			pay += cnt * A;
		}
		else if (cnt == 2)
		{
			pay += cnt * B;
		}
		else
		{
			pay += cnt * C;
		}
		cnt = 0;
	}

	cout << pay << "\n";

	return 0;
}