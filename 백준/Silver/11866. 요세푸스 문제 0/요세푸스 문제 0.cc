#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        v[i] = i + 1;
    }

    vector<int> ans;
    ans.push_back(K);
    v.erase(v.begin() + (K - 1));
    int idx = K - 1;
    while (!v.empty())
    {
        idx += K - 1;
        while (idx >= v.size())
        {
            idx %= v.size();
        }

        ans.push_back(v[idx]);
        v.erase(v.begin() + idx);
    }

    cout << "<";
    for (int i = 0; i < N - 1; i++)
    {
        cout << ans[i] << ", ";
    }
    cout << ans[N - 1] << ">\n";
    

    return 0;
}
