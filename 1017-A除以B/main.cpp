#include <bits/stdc++.h>
using namespace std;
// 算法原理：按手算除法逐位计算商和余数，避免使用超大整数类型。
// 关键步骤：每一步将当前余数乘 10 加入下一位数字。
int main() {
    string a;
    int b;
    cin >> a >> b;
    string q;
    int r = 0;
    for (char c : a) {
        r = r * 10 + c - '0';
        q += char('0' + r / b);
        r %= b;
    }
    auto p = q.find_first_not_of('0');
    cout << (p == string::npos ? "0" : q.substr(p)) << ' ' << r;
}
