#include <bits/stdc++.h>
using namespace std;
// 算法原理：从 2 开始枚举素数，输出第 M 到第 N 个，并每 10 个换行。
// 关键步骤：找到第 N 个素数后立即停止枚举。
bool prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    int m, n;
    cin >> m >> n;
    int cnt = 0, out = 0;
    for (int x = 2;; ++x)
        if (prime(x)) {
            ++cnt;
            if (cnt >= m && cnt <= n) {
                if (out)
                    cout << (out % 10 ? ' ' : '\n');
                cout << x;
                ++out;
            }
            if (cnt == n)
                break;
        }
}
