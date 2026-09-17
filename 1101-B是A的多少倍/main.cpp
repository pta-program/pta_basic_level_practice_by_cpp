#include <bits/stdc++.h>
using namespace std;
// 算法原理：截取 A 的末 D 位移到首位形成 B，再计算 B/A 的浮点比值。
// 关键步骤：用字符串拼接保留截取部分可能存在的前导零。
int main() {
    string a;
    int d;
    cin >> a >> d;
    string b = a.substr(a.size() - d) + a.substr(0, a.size() - d);
    cout << fixed << setprecision(2) << stod(b) / stod(a);
}
