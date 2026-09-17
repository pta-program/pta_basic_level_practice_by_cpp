#include <bits/stdc++.h>
using namespace std;
// 算法原理：恢复链表地址序列，将区块按从尾到头的顺序拼接，区块内部保持原序。
// 关键步骤：末尾不足 K 个结点的区块也要整体移动，但不能反转区块内部顺序。
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
    for (int i = 0, x; i < n; ++i)
        cin >> x >> a[x].d >> a[x].n;
    vector<int> v;
    for (int x = h; x != -1; x = a[x].n)
        v.push_back(x);
    vector<int> reordered;
    int groupSize = v.size() % k == 0 ? k : v.size() % k;
    for (int end = v.size(); end > 0;) {
        int start = end - groupSize;
        reordered.insert(reordered.end(), v.begin() + start, v.begin() + end);
        end = start;
        groupSize = k;
    }
    v.swap(reordered);
    for (int i = 0; i < (int)v.size(); ++i)
        cout << adr(v[i]) << ' ' << a[v[i]].d << ' ' << adr(i + 1 < (int)v.size() ? v[i + 1] : -1)
             << '\n';
}
