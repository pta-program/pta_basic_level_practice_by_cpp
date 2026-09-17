#include <bits/stdc++.h>
using namespace std;
// 算法原理：按地址恢复链表顺序，每 K 个结点反转一次并重新输出 Next。
// 关键步骤：只反转完整的 K 结点组，尾部不足 K 个结点保持原序。
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
    for (int i = 0; i < n; ++i) {
        int x, d, y;
        cin >> x >> d >> y;
        a[x] = {d, y};
    }
    vector<int> v;
    for (int x = h; x != -1; x = a[x].n)
        v.push_back(x);
    for (int i = 0; i + k <= (int)v.size(); i += k)
        reverse(v.begin() + i, v.begin() + i + k);
    for (int i = 0; i < (int)v.size(); ++i)
        cout << adr(v[i]) << ' ' << a[v[i]].d << ' ' << adr(i + 1 < (int)v.size() ? v[i + 1] : -1)
             << '\n';
}
