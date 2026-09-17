#include <bits/stdc++.h>
using namespace std;
// 算法原理：从最低位开始按每位进制表做带进位加法，0 表示十进制。
// 关键步骤：从右端对齐两个数字，缺少的高位按 0 参与计算。
int val(char c) { return isdigit((unsigned char)c) ? c - '0' : c - 'a' + 10; }
char enc(int x) { return x < 10 ? '0' + x : 'a' + x - 10; }
int main() {
    string base, a, b;
    cin >> base >> a >> b;
    int n = base.size(), L = max(a.size(), b.size());
    a = string(L - a.size(), '0') + a;
    b = string(L - b.size(), '0') + b;
    string r;
    int carry = 0;
    for (int i = 0; i < L; ++i) {
        int p = L - 1 - i, z = val(a[p]) + val(b[p]) + carry,
            rad = i < n ? base[n - 1 - i] - '0' : 10;
        if (rad == 0)
            rad = 10;
        r += enc(z % rad);
        carry = z / rad;
    }
    if (carry)
        r += enc(carry);
    reverse(r.begin(), r.end());
    auto p = r.find_first_not_of('0');
    cout << (p == string::npos ? "0" : r.substr(p));
}
