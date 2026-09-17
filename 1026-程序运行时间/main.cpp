#include <bits/stdc++.h>
using namespace std;
// 算法原理：将时钟滴答差按四舍五入换算为秒，再拆成时分秒。
// 关键步骤：使用 (差值+50)/100 实现整数四舍五入。
int main() {
    long long c1, c2;
    cin >> c1 >> c2;
    long long s = (c2 - c1 + 50) / 100;
    cout << setw(2) << setfill('0') << s / 3600 << ':' << setw(2) << s / 60 % 60 << ':' << setw(2)
         << s % 60;
}
