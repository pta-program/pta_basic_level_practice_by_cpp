#include <bits/stdc++.h>
using namespace std;
// 算法原理：以 2019 为初始四项，后续项为前四项之和的个位数字。
// 关键步骤：只保留最近四项的数字和，按题目要求输出前 n 项。
int main() {
    int n;
    cin >> n;
    string s = "2019";
    for (int i = 4; i < n; ++i) {
        int z = 0;
        for (int j = i - 4; j < i; ++j)
            z += s[j] - '0';
        s += char('0' + z % 10);
    }
    cout << s.substr(0, n);
}
