#include <bits/stdc++.h>
using namespace std;
// 算法原理：计算 A*B 后转为字符串，反转并去掉结果末尾对应的前导零。
// 关键步骤：反转后的首段零对应原乘积的末尾零，需要删除。
int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a * b);
    reverse(s.begin(), s.end());
    auto p = s.find_first_not_of('0');
    cout << (p == string::npos ? "0" : s.substr(p));
}
