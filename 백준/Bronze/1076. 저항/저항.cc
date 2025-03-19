#include <iostream>
#include <map>
#include <string>
using namespace std;

string colors[3];
map<string, pair<long long, long long>> table = {
	{"black", {0, 1}},
	{"brown", {1, 10}},
	{"red", {2, 100}},
	{"orange", {3, 1000}},
	{"yellow", {4, 10000}},
	{"green", {5, 100000}},
	{"blue", {6, 1000000}},
	{"violet", {7, 10000000}},
	{"grey", {8, 100000000}},
	{"white", {9, 1000000000}},
};

int main()  
{
	for (int i = 0; i < 3; i++)
	{
		cin >> colors[i];
	}

	long long res;

	res = (10 * table[colors[0]].first + table[colors[1]].first) * table[colors[2]].second;

	cout << res << '\n';

	return 0;
}