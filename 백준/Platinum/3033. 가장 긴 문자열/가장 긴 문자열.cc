#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

using ull = unsigned long long;

const ull BASE1 = 127;
const ull BASE2 = 131;
const ull MOD1 = 1e9 + 7;
const ull MOD2 = 1e9 + 9;

int L;
string S;

bool has_duplicate(int len)
{
    if (len == 0) return true;

    unordered_set<ull> hash_set;

    ull hash1 = 0, hash2 = 0;
    ull power1 = 1, power2 = 1;

    // 초기 해시 및 멱수 준비
    for (int i = 0; i < len; i++)
    {
        hash1 = (hash1 * BASE1 + S[i]) % MOD1;
        hash2 = (hash2 * BASE2 + S[i]) % MOD2;
        if (i != len - 1)
        {
            power1 = (power1 * BASE1) % MOD1;
            power2 = (power2 * BASE2) % MOD2;
        }
    }

    hash_set.insert((hash1 << 32) | hash2);

    for (int i = len; i < L; i++)
    {
        // 해시 갱신
        hash1 = (hash1 + MOD1 - (S[i - len] * power1) % MOD1) % MOD1;
        hash1 = (hash1 * BASE1 + S[i]) % MOD1;

        hash2 = (hash2 + MOD2 - (S[i - len] * power2) % MOD2) % MOD2;
        hash2 = (hash2 * BASE2 + S[i]) % MOD2;

        ull combined = (hash1 << 32) | hash2;

        if (hash_set.count(combined))
            return true;

        hash_set.insert(combined);
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> S;

    int lo = 1, hi = L, ans = 0;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if (has_duplicate(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
