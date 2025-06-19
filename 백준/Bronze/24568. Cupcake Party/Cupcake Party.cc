#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R, S;
    cin >> R >> S;

    long long cupcakes = R * 8 + S * 3;
    cout << cupcakes - 28 << '\n';
    return 0;
}
