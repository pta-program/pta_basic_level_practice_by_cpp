#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举 a 检查立方差为平方数，再枚举 b 验证平方和关系。
// 关键步骤：使用整数平方根校验，避免浮点平方判断误差。
bool sq(long long x) {
    long long r = sqrt((long double)x);
    return r * r == x || (r + 1) * (r + 1) == x;
}
int main() {
    int m, n;
    cin >> m >> n;
    bool any = false;
    for (long long a = m; a <= n; ++a) {
        long long z = a * a * a - (a - 1) * (a - 1) * (a - 1);
        if (!sq(z))
            continue;
        long long c = sqrt((long double)z);
        for (long long b = 1; b * b + (b - 1) * (b - 1) <= c; ++b)
            if (b * b + (b - 1) * (b - 1) == c) {
                cout << a << ' ' << b << '\n';
                any = true;
            }
    }
    if (!any)
        cout << "No Solution";
}
