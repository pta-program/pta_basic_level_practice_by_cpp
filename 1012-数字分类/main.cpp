#include <bits/stdc++.h>
using namespace std;
// 算法原理：按数字对 5 的余数分类，同时维护交错和、平均值和最大值。
// 关键步骤：用计数器控制 A2 的正负交替，并记录 A4 的样本数。
int main() {
    int n;
    cin >> n;
    int a1 = 0, a2 = 0, a3 = 0, a5 = -1, c2 = 0, c4 = 0;
    double s4 = 0;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        switch (x % 5) {
        case 0:
            if (x % 2 == 0)
                a1 += x;
            break;
        case 1:
            a2 += (c2++ % 2 ? -x : x);
            break;
        case 2:
            ++a3;
            break;
        case 3:
            s4 += x, ++c4;
            break;
        case 4:
            a5 = max(a5, x);
        }
    }
    if (a1)
        cout << a1;
    else
        cout << 'N';
    cout << ' ';
    if (c2)
        cout << a2;
    else
        cout << 'N';
    cout << ' ';
    if (a3)
        cout << a3;
    else
        cout << 'N';
    cout << ' ';
    if (c4)
        cout << fixed << setprecision(1) << s4 / c4;
    else
        cout << 'N';
    cout << ' ';
    if (a5 >= 0)
        cout << a5;
    else
        cout << 'N';
}
