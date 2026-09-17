#include <bits/stdc++.h>
using namespace std;
// 算法原理：计算每张卡片两面数字差，统计频数并按差值降序输出重复项。
// 关键步骤：差值频数大于 1 才是需要报告的重复差值。
int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        ++c[abs(i - x)];
    }
    bool first = true;
    for (int d = n - 1; d >= 0; --d)
        if (c[d] > 1) {
            cout << d << ' ' << c[d] << '\n';
            first = false;
        }
}
