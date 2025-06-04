#include <iostream>
#include <stack>

using namespace std;

long long sum = 0;
int temp;
stack<int> prv;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		sum += temp;
		
		if (temp == 0)
		{
			sum -= prv.top();
			prv.pop();
		}

		if (temp != 0)
		{
			prv.push(temp);
		}
	}

	cout << sum << "\n";

	return 0;
}