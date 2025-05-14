#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

void solve()
{
	int num = 0;
	vector<int> pos;

	string word, text;
	cin >> word;
	cin.ignore();
	getline(cin, text);

	for (int i = 0; i < word.size(); i++)
	{
		word[i] = tolower(word[i]);
	}

	for (int i = 0; i < text.size(); i++)
	{
		text[i] = tolower(text[i]);
	}

	int map_idx[26];
	memset(map_idx, -1, sizeof(map_idx));
	for (int i = 0; i < word.length(); i++)
	{
		map_idx[word[i] - 'a'] = i;
	}

	int cnt[10] = { 0, };
	for (int i = 0; i < text.size(); i++)
	{
		char ch = text[i];
		if (ch < 'a' || ch > 'z')
			continue;

		int idx = map_idx[ch - 'a'];
		if (idx == -1) continue;

		if (idx == 0)
		{
			cnt[0]++;
			if (word.length() == 1)
				pos.push_back(i + 1);
		}
		else if (cnt[idx - 1] > cnt[idx])
		{
			cnt[idx] += 1;
			if (idx == word.length() - 1)
				pos.push_back(i + 1);
		}
	}

	cout << cnt[word.length() - 1] << " ";
	for (int i = 0; i < pos.size(); i++)
	{
		if (i >= 3)
			break;
		cout << pos[i] << " ";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		solve();
	}

	return 0;
}