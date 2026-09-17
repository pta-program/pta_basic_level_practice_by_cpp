#include <bits/stdc++.h>
using namespace std;
// 算法原理：用日期字符串字典序筛选有效年龄范围内的最年长和最年轻者。
// 关键步骤：先过滤出生日期，再分别更新最小和最大日期。
struct P {
    string n, d;
};
int main() {
    int n;
    cin >> n;
    P old{"", "9999/99/99"}, young{"", "0000/00/00"};
    int cnt = 0;
    while (n--) {
        P p;
        cin >> p.n >> p.d;
        if (p.d >= "1814/09/06" && p.d <= "2014/09/06") {
            ++cnt;
            if (p.d < old.d)
                old = p;
            if (p.d > young.d)
                young = p;
        }
    }
    if (!cnt)
        cout << 0;
    else
        cout << cnt << ' ' << old.n << ' ' << young.n;
}
