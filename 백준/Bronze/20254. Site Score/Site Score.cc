#include <iostream>
using namespace std;

int main() {
    int ur, tr, uo, to;
    cin >> ur >> tr >> uo >> to;

    int score = ur * 56 + tr * 24 + uo * 14 + to * 6;

    cout << score << endl;

    return 0;
}
