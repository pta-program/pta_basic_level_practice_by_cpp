#include <bits/stdc++.h>
using namespace std;
// 算法原理：恢复两条链表，逆序较短链表后按长链表两结点、短链表一结点交替合并。
// 关键步骤：先比较两条有效链长度，再决定哪条链为长链。
struct N {
    int d, n;
};
string adr(int x) {
    if (x < 0)
        return "-1";
    ostringstream o;
    o << setw(5) << setfill('0') << x;
    return o.str();
}
vector<int> read(int h, vector<N> &a) {
    vector<int> v;
    for (int x = h; x != -1; x = a[x].n)
        v.push_back(x);
    return v;
}
int main() {
    int h1, h2, n;
    cin >> h1 >> h2 >> n;
    vector<N> a(100000);
    for (int i = 0, x; i < n; ++i)
        cin >> x >> a[x].d >> a[x].n;
    auto u = read(h1, a), v = read(h2, a);
    if (u.size() < v.size())
        swap(u, v);
    reverse(v.begin(), v.end());
    vector<int> o;
    int i = 0, j = 0;
    while (i < (int)u.size()) {
        o.push_back(u[i++]);
        if (i < (int)u.size())
            o.push_back(u[i++]);
        if (j < (int)v.size())
            o.push_back(v[j++]);
    }
    while (j < (int)v.size())
        o.push_back(v[j++]);
    for (int i = 0; i < (int)o.size(); ++i)
        cout << adr(o[i]) << ' ' << a[o[i]].d << ' ' << adr(i + 1 < (int)o.size() ? o[i + 1] : -1)
             << '\n';
}
