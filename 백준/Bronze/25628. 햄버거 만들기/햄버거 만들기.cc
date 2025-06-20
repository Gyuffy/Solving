#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    int bread = A / 2;
    int patty = B;
    int result = min(bread, patty);

    cout << result << '\n';
    return 0;
}
