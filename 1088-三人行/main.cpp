#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举两位数甲，构造调位后的乙，再由两人关系验证丙。
// 关键步骤：从 99 向下枚举，首次找到的解就是甲的最大解。
string cmp(int a, int b) { return a > b ? "Cong" : a == b ? "Ping" : "Gai"; }
int main() {
    int m, x, y;
    cin >> m >> x >> y;
    for (int a = 99; a >= 10; --a) {
        int b = a % 10 * 10 + a / 10, d = abs(a - b);
        if (d % x || b * y % x)
            continue;
        int c = d / x;
        if (b != c * y)
            continue;
        cout << a << ' ' << cmp(a, m) << ' ' << cmp(b, m) << ' ' << cmp(c, m);
        return 0;
    }
    cout << "No Solution";
}
