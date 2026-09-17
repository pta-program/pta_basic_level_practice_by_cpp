#include <bits/stdc++.h>
using namespace std;
// 算法原理：比较每个运动员到原点距离的平方，分别取最近和最远者。
// 关键步骤：不计算平方根即可比较距离大小规律。
int main() {
    int n;
    cin >> n;
    string mn, mx;
    int lo = INT_MAX, hi = -1;
    for (int i = 0; i < n; ++i) {
        string id;
        int x, y;
        cin >> id >> x >> y;
        int z = x * x + y * y;
        if (z < lo)
            lo = z, mn = id;
        if (z > hi)
            hi = z, mx = id;
    }
    cout << mn << ' ' << mx;
}
