#include <bits/stdc++.h>
using namespace std;
// 算法原理：合并相邻等重熊猫，将体重关系转成有向约束并求最小奶量增量。
// 关键步骤：拓扑计算每个等重分量需要增加的最小 100 毫升倍数。
struct DSU {
    vector<int> p;
    DSU(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a != b)
            p[b] = a;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> w(n), a(n, 200);
    for (int &x : w)
        cin >> x;
    DSU d(n);
    for (int i = 1; i < n; ++i)
        if (w[i] == w[i - 1])
            d.u(i, i - 1);
    int q = 0;
    for (int i = 0; i < n; ++i)
        if (d.f(i) == i)
            q++;
    vector<int> root(q), idx(n, -1), weight;
    for (int i = 0, j = 0; i < n; ++i)
        if (d.f(i) == i)
            idx[i] = j++, weight.push_back(w[i]);
    for (int i = 0; i < n; ++i)
        idx[i] = idx[d.f(i)];
    vector<vector<pair<int, int>>> g(q);
    vector<int> ind(q);
    for (int i = 1; i < n; ++i)
        if (idx[i] != idx[i - 1]) {
            int u = idx[i - 1], v = idx[i];
            if (w[i - 1] > w[i])
                swap(u, v);
            g[u].push_back({v, 100});
            ++ind[v];
        }
    queue<int> qu;
    vector<int> dist(q, 0);
    for (int i = 0; i < q; ++i)
        if (!ind[i])
            qu.push(i);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto [v, z] : g[u])
            dist[v] = max(dist[v], dist[u] + z), --ind[v] == 0 ? qu.push(v) : void();
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += 200 + dist[idx[i]];
    cout << sum;
}
