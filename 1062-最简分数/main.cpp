#include <bits/stdc++.h>
using namespace std;
// 算法原理：将不等式转换为 i/k 严格位于两个分数之间，并筛选互质分子。
// 关键步骤：用交叉相乘避免浮点误差，并从最小可能分子开始枚举。
using ll = long long;
int main() {
    ll a, b, c, d, k;
    scanf("%lld/%lld %lld/%lld %lld", &a, &b, &c, &d, &k);
    if (a * d > c * b)
        swap(a, c), swap(b, d);
    ll lo = a * k / b + 1;
    bool first = true;
    for (ll i = lo; i * d < c * k; ++i)
        if (gcd(i, k) == 1) {
            if (!first)
                cout << ' ';
            cout << i << '/' << k;
            first = false;
        }
}
