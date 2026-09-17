#include <bits/stdc++.h>
using namespace std;
// 算法原理：逐像素判断是否在区间 [A,B] 内，命中区间时替换为指定灰度值。
// 关键步骤：使用固定宽度和前导零控制像素输出格式。
int main() {
    int m, n, a, b, replacement;
    cin >> m >> n >> a >> b >> replacement;
    for (int i = 0; i < m * n; ++i) {
        int x;
        cin >> x;
        if (i)
            cout << (i % n ? ' ' : '\n');
        cout << setw(3) << setfill('0') << (x >= a && x <= b ? replacement : x);
    }
}
