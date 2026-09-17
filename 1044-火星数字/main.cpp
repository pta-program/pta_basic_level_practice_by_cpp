#include <bits/stdc++.h>
using namespace std;
// 算法原理：用低位和高位词表实现十进制与火星数字之间的互相转换。
// 关键步骤：十进制输入按 13 分解，火星输入按词表查找并组合。
string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                "jly",  "aug", "sep", "oct", "nov", "dec"};
string high[] = {"",    "tam", "hel", "maa", "huh", "tou", "kes",
                 "hei", "elo", "syy", "lok", "mer", "jou"};
int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        if (isdigit((unsigned char)s[0])) {
            int x = stoi(s);
            if (x < 13)
                cout << low[x];
            else
                cout << high[x / 13] << (x % 13 ? ' ' + low[x % 13] : "");
        } else {
            stringstream ss(s);
            string a, b;
            ss >> a >> b;
            int x = find(low, low + 13, a) - low;
            if (x < 13) {
                if (b.empty())
                    cout << x;
                else
                    cout << x + (find(high, high + 13, b) - high) * 13;
            } else {
                int h = find(high, high + 13, a) - high;
                cout << h * 13 + (b.empty() ? 0 : find(low, low + 13, b) - low);
            }
        }
        if (n)
            cout << '\n';
    }
}
