#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string stripLeadingZeros(const string &s)
{
    size_t pos = s.find_first_not_of('0');
    return (pos == string::npos) ? "0" : s.substr(pos);
}

int compareAbs(const string &a, const string &b)
{
    string x = stripLeadingZeros(a);
    string y = stripLeadingZeros(b);

    if (x.size() != y.size())
    {
        return (x.size() < y.size()) ? -1 : 1;
    }
    return (x < y) ? -1 : (x > y);
}

string addPositive(const string &a, const string &b)
{
    string res;
    int carry = 0;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res.push_back(static_cast<char>(sum % 10 + '0'));
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string subPositive(const string &a, const string &b)
{
    string res;
    int borrow = 0;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;

    while (i >= 0)
    {
        int diff = (a[i] - '0') - borrow;
        if (j >= 0) diff -= (b[j--] - '0');

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        res.push_back(static_cast<char>(diff + '0'));
        --i;
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

string multiplyPositive(const string &a, const string &b)
{
    if (a == "0" || b == "0") return "0";

    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());
    vector<int> prod(n + m, 0);

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            int idxLow  = i + j + 1;
            int idxHigh = i + j;
            int cur     = (a[i] - '0') * (b[j] - '0') + prod[idxLow];

            prod[idxLow]  = cur % 10;
            prod[idxHigh] += cur / 10;
        }
    }

    string res;
    size_t k = 0;
    while (k < prod.size() && prod[k] == 0) ++k;
    for (; k < prod.size(); ++k) res.push_back(static_cast<char>(prod[k] + '0'));
    return res;
}

string addBig(const string &a, const string &b)
{
    bool negA = !a.empty() && (a[0] == '-');
    bool negB = !b.empty() && (b[0] == '-');
    string absA = negA ? a.substr(1) : a;
    string absB = negB ? b.substr(1) : b;

    if (negA == negB)
    {
        string res = addPositive(absA, absB);
        return negA ? "-" + res : res;
    }
    else
    {
        int cmp = compareAbs(absA, absB);
        if (cmp == 0) return "0";

        string res = (cmp > 0) ? subPositive(absA, absB)
                               : subPositive(absB, absA);
        bool negativeResult = (cmp > 0) ? negA : negB;
        return negativeResult ? "-" + res : res;
    }
}

string subBig(const string &a, const string &b)
{
    string negB = (b[0] == '-') ? b.substr(1) : "-" + b;
    return addBig(a, negB);
}

string mulBig(const string &a, const string &b)
{
    bool negA = !a.empty() && (a[0] == '-');
    bool negB = !b.empty() && (b[0] == '-');
    string absA = negA ? a.substr(1) : a;
    string absB = negB ? b.substr(1) : b;

    string res = multiplyPositive(absA, absB);
    if (res == "0") return "0";
    return (negA ^ negB) ? "-" + res : res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    if (!(cin >> A >> B))
    {
        return 0;
    }

    cout << addBig(A, B) << '\n';
    cout << subBig(A, B) << '\n';
    cout << mulBig(A, B) << '\n';

    return 0;
}
