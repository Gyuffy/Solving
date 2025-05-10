#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int w;
};
struct Compare
{
    bool operator()(const pair<long long,int>& a,
                    const pair<long long,int>& b) const
    {
        return a.first > b.first;   // 최소 힙
    }
};

const long long INF = 4'000'000'000LL;

vector<long long> dijkstra(int start, const vector<vector<Edge>>& g)
{
    int V = g.size() - 1;
    vector<long long> dist(V + 1, INF);
    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   Compare> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, now] = pq.top();
        pq.pop();
        if (d != dist[now]) continue;

        for (const auto& e : g[now])
        {
            long long nd = d + e.w;
            if (nd < dist[e.to])
            {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V, E, A, B;
    if (!(cin >> N >> V >> E >> A >> B)) return 0;

    vector<int> emp(N);
    for (int& x : emp) cin >> x;           // 직원 근무지

    vector<vector<Edge>> g(V + 1);
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto distA = dijkstra(A, g);
    auto distB = dijkstra(B, g);

    long long sum = 0;
    for (int x : emp)
    {
        if (distA[x] == INF || distB[x] == INF)
        {
            cout << -1 << '\n';
            return 0;
        }
        sum += distA[x] + distB[x];
    }
    cout << sum << '\n';
    return 0;
}
