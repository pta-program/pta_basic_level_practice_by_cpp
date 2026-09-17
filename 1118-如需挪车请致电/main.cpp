#include <bits/stdc++.h>
using namespace std;
// 算法原理：识别文字数字或唯一运算符，计算每条公式得到的个位数字。
// 关键步骤：先处理 sqrt 和拼音等特殊形式，再处理二元运算。
int main() {
    map<string, int> v{{"ling", 0}, {"yi", 1},  {"er", 2}, {"san", 3}, {"si", 4},
                       {"wu", 5},   {"liu", 6}, {"qi", 7}, {"ba", 8},  {"jiu", 9}};
    for (int i = 0; i < 11; ++i) {
        string s;
        cin >> s;
        size_t p = s.find("sqrt");
        int ans = 0;
        if (p == 0)
            ans = sqrt(stoi(s.substr(4)));
        else if (v.count(s))
            ans = v[s];
        else {
            char op;
            for (char c : s)
                if (string("+-*/%^ ").find(c) != string::npos) {
                    op = c;
                    break;
                }
            p = s.find(op);
            int a = stoi(s.substr(0, p)), b = stoi(s.substr(p + 1));
            if (op == '+')
                ans = a + b;
            if (op == '-')
                ans = a - b;
            if (op == '*')
                ans = a * b;
            if (op == '/')
                ans = a / b;
            if (op == '%')
                ans = a % b;
            if (op == '^')
                ans = pow(a, b);
        }
        cout << ans;
    }
}
