#include <bits/stdc++.h>
using namespace std;
// 算法原理：逐个计算复特征值模长 sqrt(a^2+b^2)，取最大值。
// 关键步骤：比较模长平方也可避免额外开方误差。
int main() {
    int n;
    cin >> n;
    double ans = 0;
    while (n--) {
        double a, b;
        cin >> a >> b;
        ans = max(ans, sqrt(a * a + b * b));
    }
    cout << fixed << setprecision(2) << ans;
}
