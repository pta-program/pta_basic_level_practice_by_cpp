#include <bits/stdc++.h>
using namespace std;
// 算法原理：先求和，再反复取模和除法转换为目标进制。
// 关键步骤：特殊处理和为 0 的情况，避免空结果。
int main() {
    long long a, b;
    int d;
    cin >> a >> b >> d;
    long long n = a + b;
    string s;
    if (!n)
        s = "0";
    while (n) {
        s += char('0' + n % d);
        n /= d;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
