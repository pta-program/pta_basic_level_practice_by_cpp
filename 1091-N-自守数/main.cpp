#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举 N=1..9，计算 N*K*K 并检查其末尾是否等于 K。
// 关键步骤：用 10 的幂得到 K 的位数，从而截取乘积末尾。
int main() {
    int m;
    cin >> m;
    while (m--) {
        long long k;
        cin >> k;
        bool ok = 0;
        for (int n = 1; n < 10; ++n) {
            long long z = n * k * k, p = 1;
            for (long long x = k; x; x /= 10)
                p *= 10;
            if (z % p == k) {
                cout << n << ' ' << z;
                ok = 1;
                break;
            }
        }
        if (!ok)
            cout << "No";
        if (m)
            cout << '\n';
    }
}
