#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;   // 119·2^23 + 1
const int G   = 3;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void ntt(vector<int>& a, bool invert) {
    int n = (int)a.size();

    // bit-reverse
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = mod_pow(G, (MOD - 1) / len);
        if (invert) wlen = mod_pow(wlen, MOD - 2);   // wlen^{-1}

        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j];
                int v = int(a[i + j + len / 2] * 1LL * w % MOD);
                a[i + j]             = (u + v < MOD) ? u + v : u + v - MOD;
                a[i + j + len / 2]   = (u - v >= 0) ? u - v : u - v + MOD;
                w = w * wlen % MOD;
            }
        }
    }
    if (invert) {
        long long inv_n = mod_pow(n, MOD - 2);
        for (int &x : a) x = int(x * inv_n % MOD);
    }
}

vector<int> multiply_bigints(const string& A, const string& B) {
    if (A == "0" || B == "0") return {0};

    int n = (int)A.size(), m = (int)B.size();
    int N = 1; while (N < n + m) N <<= 1;

    vector<int> fa(N), fb(N);
    for (int i = 0; i < n; ++i) fa[i] = A[n - 1 - i] - '0';
    for (int i = 0; i < m; ++i) fb[i] = B[m - 1 - i] - '0';

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < N; ++i) fa[i] = int(1LL * fa[i] * fb[i] % MOD);
    ntt(fa, true);

    // 양수 보정 후 10진수 캐리
    long long carry = 0;
    for (int i = 0; i < N; ++i) {
        long long cur = (fa[i] + MOD) % MOD + carry;   // MOD보다 확실히 작음
        fa[i] = int(cur % 10);
        carry = cur / 10;
    }
    while (carry) {
        fa.push_back(int(carry % 10));
        carry /= 10;
    }
    while (fa.size() > 1 && fa.back() == 0) fa.pop_back();
    reverse(fa.begin(), fa.end());
    return fa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string A, B;
    cin >> N >> M >> A >> B;

    vector<int> ans = multiply_bigints(A, B);
    for (int d : ans) cout << d;
    cout << '\n';
    return 0;
}
