#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int HH, MM;
    cin >> HH >> MM;

    const int start_minutes = 9 * 60;
    int submit_minutes = HH * 60 + MM;
    cout << submit_minutes - start_minutes;
    return 0;
}
