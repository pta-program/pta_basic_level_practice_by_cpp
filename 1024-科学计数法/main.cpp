#include <bits/stdc++.h>
using namespace std;
// 算法原理：拆分尾数和指数，移除小数点后按指数调整小数点位置。
// 关键步骤：根据新小数点位置分别补零、整体输出或插入小数点。
int main() {
    string s;
    cin >> s;
    bool neg = s[0] == '-';
    int e = s.find('E');
    string m = s.substr(1, e - 1);
    int ex = stoi(s.substr(e + 1));
    string d = m.substr(0, m.find('.')) + m.substr(m.find('.') + 1);
    int point = m.find('.') + ex;
    cout << (neg ? "-" : "");
    if (point <= 0)
        cout << "0." << string(-point, '0') << d;
    else if (point >= (int)d.size())
        cout << d << string(point - d.size(), '0');
    else
        cout << d.substr(0, point) << '.' << d.substr(point);
}
