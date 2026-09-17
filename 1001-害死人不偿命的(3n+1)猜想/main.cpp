#include <bits/stdc++.h>
using namespace std;
// 算法原理：直接模拟奇偶变换，统计从 n 变为 1 所需的步数。
// 关键步骤：奇数先执行 3n+1 再除以 2，偶数直接除以 2。
int main() {
    long long n;
    if (!(cin >> n))
        return 0;
    int c = 0;
    while (n != 1) {
        n = n % 2 ? (3 * n + 1) / 2 : n / 2;
        ++c;
    }
    cout << c;
}
