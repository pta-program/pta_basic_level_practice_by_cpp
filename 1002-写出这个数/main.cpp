#include <bits/stdc++.h>
using namespace std;
// 算法原理：用字符串保存超大整数，累加各字符数字后逐位映射为拼音。
// 关键步骤：输入不转整数，避免超过内置整数范围。
int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (char c : s)
        sum += c - '0';
    string p[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"},
           t = to_string(sum);
    for (int i = 0; i < (int)t.size(); ++i) {
        if (i)
            cout << ' ';
        cout << p[t[i] - '0'];
    }
}
