#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> melody = {
		"C", "C#", "D", "D#", "E", "F",
		"F#", "G", "G#", "A", "A#", "B"
	};

	set<int> semiTone = { 1, 3, 6, 8, 10 };

	vector<int> naturalNotes = { 0, 2, 4, 5, 7, 9, 11 };

	int n;
	cin >> n;
	vector<int> sheet(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> sheet[i];
	}

	vector<pair<string, string>> results;

	for (int i : naturalNotes)
	{
		int cur = i;
		bool valid = true;

		for (int j = 0; j < n; ++j)
		{
			cur = (cur + sheet[j] + 12) % 12;
			if (semiTone.count(cur))
			{
				valid = false;
				break;
			}
		}

		if (valid)
		{
			results.emplace_back(melody[i], melody[cur]);
		}
	}

	sort(results.begin(), results.end());

	for (auto& p : results)
	{
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}
