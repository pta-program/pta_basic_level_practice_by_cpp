#include <bits/stdc++.h>
using namespace std;
// 算法原理：求不超过 N 的最大沙漏层数，按上半部分和下半部分对称输出。
// 关键步骤：总字符数为 2*k*k-1，剩余字符单独输出。
int main() {
    int n;
    char c;
    cin >> n >> c;
    int k = 1;
    while (2 * (k + 1) * (k + 1) - 1 <= n)
        ++k;
    for (int i = k; i >= 1; --i)
        cout << string(k - i, ' ') << string(2 * i - 1, c) << '\n';
    for (int i = 2; i <= k; ++i)
        cout << string(k - i, ' ') << string(2 * i - 1, c) << '\n';
    cout << n - (2 * k * k - 1);
}
