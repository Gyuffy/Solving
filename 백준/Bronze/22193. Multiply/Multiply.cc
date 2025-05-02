#include <bits/stdc++.h>
using namespace std;

// ---- 자리수 곱셈 O(N*M) ----
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;          // 첫 줄: 각 수의 자리수
    string A, B;       // 두 번째·세 번째 줄: 실제 숫자
    cin >> N >> M;
    cin >> A >> B;

    // 둘 중 하나가 0이면 바로 종료
    if (A == "0" || B == "0") {
        cout << 0 << '\n';
        return 0;
    }

    // 결과 자릿수는 최대 N+M
    vector<int> res(N + M, 0);

    // 끝자리부터 손곱셈 (A[i]*B[j] → res[i+j+1])
    for (int i = N - 1; i >= 0; --i) {
        int da = A[i] - '0';
        for (int j = M - 1; j >= 0; --j) {
            int db = B[j] - '0';
            int idx = i + j + 1;

            int sum = da * db + res[idx];
            res[idx]     = sum % 10;      // 현재 자리
            res[idx - 1] += sum / 10;     // 올림
        }
    }

    // 출력: 맨 앞의 0은 생략
    int pos = 0;
    while (pos < (int)res.size() && res[pos] == 0) ++pos;
    for (; pos < (int)res.size(); ++pos) cout << res[pos];
    cout << '\n';
    return 0;
}
