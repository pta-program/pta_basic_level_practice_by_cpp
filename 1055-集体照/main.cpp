#include <bits/stdc++.h>
using namespace std;
// 算法原理：按身高降序分配各排，最高者居中，其余人员按先左后右交替摆放。
// 关键步骤：最后一排承担余数人数，其余各排人数相同。
struct P {
    string n;
    int h;
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<P> a(n);
    for (auto &x : a)
        cin >> x.n >> x.h;
    sort(a.begin(), a.end(),
         [](const P &x, const P &y) { return x.h != y.h ? x.h > y.h : x.n < y.n; });
    int base = n / k, extra = n % k, pos = 0;
    for (int row = k; row >= 1; --row) {
        int len = base + (row == k ? extra : 0);
        vector<string> out(len);
        int middle = len / 2;
        out[middle] = a[pos].n;
        for (int i = 1; i < len; ++i) {
            int index = i % 2 ? middle - (i + 1) / 2 : middle + i / 2;
            out[index] = a[pos + i].n;
        }
        for (int i = 0; i < len; ++i)
            cout << (i ? " " : "") << out[i];
        cout << '\n';
        pos += len;
    }
}
