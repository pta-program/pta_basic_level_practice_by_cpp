#include <bits/stdc++.h>
using namespace std;
// 算法原理：直接统计输入字符串中 0 到 9 的出现次数。
// 关键步骤：只输出出现次数非零的数字。
int main() {
    string s;
    cin >> s;
    int c[10] = {};
    for (char x : s)
        ++c[x - '0'];
    for (int i = 0; i < 10; ++i)
        if (c[i])
            cout << i << ':' << c[i] << '\n';
}
