#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int l = 0, r = static_cast<int>(s.size()) - 1;
    bool is_palindrome = true;

    while (l < r) {
        if (s[l] != s[r]) {
            is_palindrome = false;
            break;
        }
        ++l;
        --r;
    }

    cout << (is_palindrome ? "true" : "false");
    return 0;
}
