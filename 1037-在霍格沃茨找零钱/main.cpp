#include <bits/stdc++.h>
using namespace std;
// 算法原理：把加隆、西可、纳特统一换算成最小单位后相减再还原。
// 关键步骤：先处理金额方向，再按 17 和 29 的进制关系拆分。
int main() {
    int a, b, c, d, e, f;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
    long long x = a * 17 * 29 + b * 29 + c, y = d * 17 * 29 + e * 29 + f, z = y - x;
    if (z < 0)
        cout << '-', z = -z;
    cout << z / (17 * 29) << '.' << z / 29 % 17 << '.' << z % 29;
}
