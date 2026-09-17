#include <bits/stdc++.h>
using namespace std;
// 算法原理：按单位售价从高到低贪心销售，最后一种可销售部分库存。
// 关键步骤：每次销售 min(需求量, 库存量)，需求满足后立即结束。
struct M {
    double q, p;
};
int main() {
    int n;
    double d;
    cin >> n >> d;
    vector<double> q(n), p(n);
    for (auto &x : q)
        cin >> x;
    for (auto &x : p)
        cin >> x;
    vector<M> a;
    for (int i = 0; i < n; ++i)
        a.push_back({q[i], p[i] / q[i]});
    sort(a.begin(), a.end(), [](M &a, M &b) { return a.p > b.p; });
    double ans = 0;
    for (auto &x : a) {
        double t = min(d, x.q);
        ans += t * x.p;
        d -= t;
        if (d <= 0)
            break;
    }
    cout << fixed << setprecision(2) << ans;
}
