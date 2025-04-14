#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A, B;
int strokes[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	int len = A.length();
	vector<int> add;
	for (int i = 0; i < len; i++)
	{
		add.push_back(strokes[A[i] - 'A']);
		add.push_back(strokes[B[i] - 'A']);
	}

	while (1)
	{
		vector<int> res;
		for (int i = 0; i < add.size() - 1; i++)
		{
			res.push_back((add[i] + add[i + 1]) % 10);
		}

		add = res;
		if (add.size() == 2)
		{
			cout << add[0] << add[1] << "\n";
			break;
		}
	}


	return 0;
}