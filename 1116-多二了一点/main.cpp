#include <bits/stdc++.h>
using namespace std;
// 算法原理：拆成前后两半，用字符串大整数加 2 比较后半是否恰好多 2。
// 关键步骤：对两半去除显示前导零，但不改变数值比较结果。
string norm(string s) {
    auto p = s.find_first_not_of('0');
    return p == string::npos ? "0" : s.substr(p);
}
string plus2(string s) {
    s = norm(s);
    int c = 2;
    for (int i = s.size() - 1; i >= 0 && c; --i) {
        int z = s[i] - '0' + c;
        s[i] = '0' + z % 10;
        c = z / 10;
    }
    if (c)
        s = '1' + s;
    return s;
}
int main() {
    string s;
    cin >> s;
    if (s.size() % 2) {
        cout << "Error: " << s.size() << " digit(s)";
        return 0;
    }
    int k = s.size() / 2;
    string y = norm(s.substr(0, k)), x = norm(s.substr(k));
    bool ok = x == plus2(y);
    cout << (ok ? "Yes: " : "No: ") << x << " - " << y << (ok ? " = 2" : " != 2");
}
