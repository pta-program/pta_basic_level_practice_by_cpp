#include <bits/stdc++.h>
using namespace std;
// 算法原理：统计 String 六个字符，每轮按固定顺序消耗并输出一个字符。
// 关键步骤：忽略其他字符，直到六类计数全部消耗完毕。
int main() {
    string s;
    cin >> s;
    string t = "String";
    int c[6] = {};
    for (char x : s) {
        int p = t.find(x);
        if (p >= 0)
            ++c[p];
    }
    while (*max_element(c, c + 6)) {
        for (int i = 0; i < 6; ++i)
            if (c[i])
                cout << t[i], --c[i];
    }
}
