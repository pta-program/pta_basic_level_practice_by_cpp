#include <bits/stdc++.h>
using namespace std;
// 算法原理：逐项应用 (a*x^n)' = (a*n)*x^(n-1)，忽略指数为 0 的项。
// 关键步骤：若所有项都被忽略，按零多项式输出 0 0。
int main() {
    long long a, n;
    bool first = true, any = false;
    while (cin >> a >> n) {
        if (n == 0)
            continue;
        any = true;
        if (!first)
            cout << ' ';
        cout << a * n << ' ' << n - 1;
        first = false;
    }
    if (!any)
        cout << "0 0";
}
