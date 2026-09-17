#include <bits/stdc++.h>
using namespace std;
// 算法原理：逐项验证小数格式和数值范围，只对合法数字累加求平均。
// 关键步骤：非法输入立即输出错误信息，合法输入参与计数和求和。
bool valid(string s) {
    int dots = 0, digits = 0, fractionDigits = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '.') {
            if (++dots > 1)
                return false;
        } else if (isdigit((unsigned char)s[i]))
            ++digits, fractionDigits += dots > 0;
        else if ((s[i] == '+' || s[i] == '-') && i == 0) {
        } else
            return false;
    }
    if (!digits || fractionDigits > 2)
        return false;
    try {
        double x = stod(s);
        return x >= -1000 && x <= 1000;
    } catch (...) {
        return false;
    }
}
int main() {
    int n;
    cin >> n;
    double sum = 0;
    int c = 0;
    while (n--) {
        string s;
        cin >> s;
        if (valid(s)) {
            sum += stod(s);
            ++c;
        } else
            cout << "ERROR: " << s << " is not a legal number\n";
    }
    if (c == 0)
        cout << "The average of 0 numbers is Undefined";
    else if (c == 1)
        cout << "The average of 1 number is " << fixed << setprecision(2) << sum;
    else
        cout << "The average of " << c << " numbers is " << fixed << setprecision(2) << sum / c;
}
