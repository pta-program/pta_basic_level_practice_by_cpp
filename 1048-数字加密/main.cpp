#include <bits/stdc++.h>
using namespace std;
// 算法原理：从右向左按奇偶位分别进行模 13 加法和模 10 减法。
// 关键步骤：先补齐两串长度，再按照从右侧开始的位序计算。
int main() {
    string a, b;
    cin >> a >> b;
    int n = max(a.size(), b.size());
    a = string(n - a.size(), '0') + a;
    b = string(n - b.size(), '0') + b;
    string ans;
    for (int i = n - 1, k = 0; i >= 0; --i, ++k) {
        int x = a[i] - '0', y = b[i] - '0';
        if (k % 2 == 0) {
            int z = (x + y) % 13;
            ans += string("0123456789JQK")[z];
        } else {
            int z = (y - x + 10) % 10;
            ans += char('0' + z);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
