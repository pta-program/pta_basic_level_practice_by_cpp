#include <bits/stdc++.h>
using namespace std;
// 算法原理：逐题比较学生答案和标准答案，匹配时累加该题分值。
// 关键步骤：每个学生独立计算总分，不修改标准答案数组。
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    for (int q = 0; q < n; ++q) {
        int ans = 0;
        for (int i = 0, x; i < m; ++i)
            cin >> x, ans += x == b[i] ? a[i] : 0;
        cout << ans << '\n';
    }
}
