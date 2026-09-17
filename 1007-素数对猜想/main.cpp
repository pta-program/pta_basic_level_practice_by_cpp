#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举相差 2 的相邻候选数并用试除法判断两者是否为素数。
// 关键步骤：只枚举 i 和 i+2，避免重复统计同一素数对。
bool prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i + 2 <= n; ++i)
        if (prime(i) && prime(i + 2))
            ++ans;
    cout << ans;
}
