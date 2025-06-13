#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct DSU
{
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) ++rank[a];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> x(N + 1), y(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> x[i] >> y[i];
    }

    DSU dsu(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }

    const long long INF = numeric_limits<long long>::max();
    vector<int> minX(N + 1, 1000000001), minY(N + 1, 1000000001);
    vector<int> maxX(N + 1, -1000000001), maxY(N + 1, -1000000001);

    for (int i = 1; i <= N; ++i)
    {
        int root = dsu.find(i);
        minX[root] = min(minX[root], x[i]);
        maxX[root] = max(maxX[root], x[i]);
        minY[root] = min(minY[root], y[i]);
        maxY[root] = max(maxY[root], y[i]);
    }

    long long answer = INF;
    for (int i = 1; i <= N; ++i)
    {
        if (dsu.find(i) != i) continue;

        long long width  = static_cast<long long>(maxX[i]) - minX[i];
        long long height = static_cast<long long>(maxY[i]) - minY[i];
        long long perim  = 2LL * (width + height);
        answer = min(answer, perim);
    }

    cout << answer << '\n';
    return 0;
}
