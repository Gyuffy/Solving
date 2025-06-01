#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> last;
int mid = 0, small = 0;

bool solve(string& str)
{
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '[')
		{
			mid++;
			last.push('[');
		}
		else if ((str[i] == ']' || str[i] == ')') && last.empty())
		{
			return false;
		}
		else if (str[i] == ']' && last.top() == '[')
		{
			mid--;
			last.pop();
		}
		else if (str[i] == '(')
		{
			small++;
			last.push('(');
		}
		else if (str[i] == ')' && last.top() == '(')
		{
			small--;
			last.pop();
		}
		else if (str[i] == ']' && last.top() != '[')
		{
			return false;
		}
		else if (str[i] == ')' && last.top() != '(')
		{
			return false;
		}
	}

	if (mid == 0 && small == 0 && str[len - 1] == '.')
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	//cin.ignore();

	while (true)
	{
		while (!last.empty())
		{
			last.pop();
		}
		mid = 0;
		small = 0;
		getline(cin, str);
		if (str == ".")
		{
			break;
		}

		if (solve(str))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}