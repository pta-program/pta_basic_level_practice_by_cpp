#include <bits/stdc++.h>
using namespace std;
// 算法原理：统计每套房低于阈值的天数，按“超过一半”和“超过 D 天”分类。
// 关键步骤：只有低于 E 的天数超过一半才算疑似空置。
int main() {
    int n, d;
    double e;
    cin >> n >> e >> d;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int k, total, c = 0;
        cin >> k;
        total = k;
        for (int j = 0; j < k; ++j) {
            double x;
            cin >> x, c += x < e;
        }
        if (c > total / 2.0)
            ++(total > d ? b : a);
    }
    cout << fixed << setprecision(1) << 100.0 * a / n << "% " << 100.0 * b / n << '%';
}
