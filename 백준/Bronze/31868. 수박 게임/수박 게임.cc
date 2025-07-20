#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int i = 1; i < N; ++i) {
        K /= 2;
    }
    cout << K;
    return 0;
}
