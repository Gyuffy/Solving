#include <iostream>
#include <list>
#include <string>
using namespace std;

string str;
int M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	list<char> text(str.begin(), str.end());

	list<char>::iterator cur = text.end();

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		char cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (cur != text.begin())
				cur--;
			break;
		case 'D':
			if (cur != text.end())
				cur++;
			break;
		case 'B':
			if (cur != text.begin())
			{
				cur--;
				cur = text.erase(cur);
			}
			break;
		case 'P':
			char ch;
			cin >> ch;
			text.insert(cur, ch);
			break;
		default:
			break;
		}
	}

	cur = text.begin();

	for (int i = 0; i < text.size(); i++)
	{
		cout << *cur;
		cur++;
	}

	cout << "\n";

	return 0;
}