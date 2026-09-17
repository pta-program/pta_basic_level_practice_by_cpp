#include <bits/stdc++.h>
using namespace std;
// 算法原理：最多迭代 10 次，将当前数与其逆序数做大整数加法并检查回文。
// 关键步骤：用字符串逐位相加，避免千位数字溢出。
string add(string a, string b) {
    int c = 0;
    string r;
    for (int i = a.size() - 1; i >= 0; --i) {
        int z = a[i] - '0' + b[i] - '0' + c;
        r += char('0' + z % 10);
        c = z / 10;
    }
    if (c)
        r += '1';
    reverse(r.begin(), r.end());
    return r;
}
bool pal(string &s) { return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); }
int main() {
    string s;
    cin >> s;
    for (int i = 0; i <= 10; ++i) {
        if (pal(s)) {
            cout << s << " is a palindromic number.";
            return 0;
        }
        if (i == 10)
            break;
        string t = s;
        reverse(t.begin(), t.end());
        cout << s << " + " << t << " = " << (s = add(s, t)) << '\n';
    }
    cout << "Not found in 10 iterations.";
}
