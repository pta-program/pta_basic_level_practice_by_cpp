#include <bits/stdc++.h>
using namespace std;
// 算法原理：从低位进行 30 进制大整数加法，数字 10 到 29 映射为 a 到 t。
// 关键步骤：逐位保存余数字符，并把商作为下一位进位。
int val(char c) { return isdigit((unsigned char)c) ? c - '0' : c - 'a' + 10; }
char enc(int x) { return x < 10 ? '0' + x : 'a' + x - 10; }
int main() {
    string a, b;
    cin >> a >> b;
    int n = max(a.size(), b.size()), carry = 0;
    string r;
    for (int i = 0; i < n; ++i) {
        int x = i < a.size() ? val(a[a.size() - 1 - i]) : 0,
            y = i < b.size() ? val(b[b.size() - 1 - i]) : 0, z = x + y + carry;
        r += enc(z % 30);
        carry = z / 30;
    }
    if (carry)
        r += enc(carry);
    reverse(r.begin(), r.end());
    auto p = r.find_first_not_of('0');
    cout << (p == string::npos ? "0" : r.substr(p));
}
