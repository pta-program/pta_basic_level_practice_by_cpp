#include <bits/stdc++.h>
using namespace std;
// 算法原理：沿原链表遍历，将结点稳定地分到负数、[0,K] 和大于 K 三组。
// 关键步骤：按三组顺序拼接地址序列，保证每组内部相对顺序不变。
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
int main() {
    int h, n, k;
    cin >> h >> n >> k;
    vector<N> a(100000);
    for (int i = 0, x; i < n; ++i) {
        cin >> x >> a[x].d >> a[x].n;
    }
    vector<int> v[3];
    for (int x = h; x != -1; x = a[x].n)
        v[a[x].d < 0 ? 0 : a[x].d <= k ? 1 : 2].push_back(x);
    vector<int> o;
    for (auto &z : v)
        o.insert(o.end(), z.begin(), z.end());
    for (int i = 0; i < (int)o.size(); ++i)
        cout << adr(o[i]) << ' ' << a[o[i]].d << ' ' << adr(i + 1 < (int)o.size() ? o[i + 1] : -1)
             << '\n';
}
