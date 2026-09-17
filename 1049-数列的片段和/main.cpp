#include <bits/stdc++.h>
using namespace std;
// 算法原理：第 i 个元素出现在 (i+1)*(N-i) 个连续子段中，按贡献求和。
// 关键步骤：每个元素只读取一次，无需枚举所有子段。
int main() {
    int n;
    cin >> n;
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        long double x;
        cin >> x;
        ans += x * (i + 1) * (n - i);
    }
    cout << fixed << setprecision(2) << (double)ans;
}
