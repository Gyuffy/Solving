#include <iostream>
#include <vector>
using namespace std;

inline bool unique_digits(int num) {
    int mask = 0;
    while (num) {
        int d = num % 10;
        if (mask & (1 << d)) return false;
        mask |= 1 << d;
        num /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> queries;
    int n, maxN = 0;
    while (cin >> n && n != 0) {
        queries.push_back(n);
        if (n > maxN) maxN = n;
    }
    if (maxN == 0) return 0;

    vector<int> ans(maxN + 1);   // 1-based
    int cnt = 0;
    for (int num = 1; cnt < maxN; ++num) {
        if (unique_digits(num))
            ans[++cnt] = num;
    }

    for (int q : queries)
        cout << ans[q] << '\n';

    return 0;
}
