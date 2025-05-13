#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string input;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num, tmp;

	for (int i = 0; i < 3; i++)
	{
		cin >> input;
		if (isdigit(input[0]))
		{
			num = stoi(input);
			tmp = 3 - i;
		}
	}

	int ans_num = num + tmp;
	string output;

	if (ans_num % 3 == 0 && ans_num % 5 == 0)
		output = "FizzBuzz";
	else if (ans_num % 3 == 0)
		output = "Fizz";
	else if (ans_num % 5 == 0)
		output = "Buzz";
	else
		output = to_string(ans_num);

	cout << output + "\n";

	return 0;
}