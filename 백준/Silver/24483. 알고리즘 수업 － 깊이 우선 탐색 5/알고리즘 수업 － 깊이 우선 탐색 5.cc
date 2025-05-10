#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100000 + 5;
vector<int> g[MAX_N];
bool visited[MAX_N];
int depthArr[MAX_N];
int orderArr[MAX_N];
int N, M, R;

ll total = 0;
int curOrder = 1;

void dfs(int u, int d)
{
    visited[u]   = true;
    depthArr[u]  = d;
    orderArr[u]  = curOrder;
    total       += 1LL * d * curOrder;

    for (int v : g[u])
    {
        if (visited[v]) continue;
        ++curOrder;
        dfs(v, d + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;
    for (int i = 0, a, b; i < M; ++i)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
        sort(g[i].begin(), g[i].end());

    fill(depthArr, depthArr + N + 1, -1);
    dfs(R, 0);

    cout << total << '\n';
    return 0;
}
