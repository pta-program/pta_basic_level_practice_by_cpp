#include <bits/stdc++.h>
using namespace std;
// 算法原理：依次检查长度、字符合法性以及字母和数字是否齐全。
// 关键步骤：按题目规定的错误优先级输出第一条不满足的条件。
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        bool len = s.size() >= 6 && s.size() <= 20, letter = 0, dig = 0, ok = 1;
        for (char c : s) {
            if (isalpha((unsigned char)c))
                letter = 1;
            else if (isdigit((unsigned char)c))
                dig = 1;
            else if (c == '.')
                continue;
            else
                ok = 0;
        }
        if (!len)
            cout << "Your password is tai duan le.";
        else if (!ok)
            cout << "Your password is tai luan le.";
        else if (!letter)
            cout << "Your password needs zi mu.";
        else if (!dig)
            cout << "Your password needs shu zi.";
        else
            cout << "Your password is wan mei.";
        if (n)
            cout << '\n';
    }
}
