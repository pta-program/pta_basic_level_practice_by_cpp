#include <bits/stdc++.h>
using namespace std;
// 算法原理：按保留位检查舍入位及尾数，分别实现四舍五入、截断和银行家舍入。
// 关键步骤：字符串进位从保留位末端向整数部分传播。
string process(int type, string s, int D) {
    bool neg = s[0] == '-';
    if (neg)
        s = s.substr(1);
    size_t dot = s.find('.');
    string ip = dot == string::npos ? s : s.substr(0, dot),
           fp = dot == string::npos ? "" : s.substr(dot + 1);
    string all = ip + fp;
    int cut = ip.size() + D;
    bool round = false;
    if (cut < (int)all.size()) {
        char q = all[cut];
        bool tail = false;
        for (int i = cut + 1; i < (int)all.size(); ++i)
            tail |= all[i] != '0';
        if (type == 1)
            round = q >= '5';
        else if (type == 3)
            round = q > '5' || (q == '5' && (tail || ((cut ? all[cut - 1] : '0' - 0) % 2 == 1)));
    }
    if (round) {
        int i = cut - 1;
        while (i >= 0 && all[i] == '9')
            all[i--] = '0';
        if (i < 0)
            all = '1' + all;
        else
            ++all[i];
    }
    if ((int)all.size() < cut)
        all += string(cut - all.size(), '0');
    string out = all.substr(0, ip.size());
    string dec = cut > ip.size() ? all.substr(ip.size(), D) : "";
    if ((int)dec.size() < D)
        dec += string(D - dec.size(), '0');
    return (neg ? "-" : "") + out + '.' + dec;
}
int main() {
    int n, d;
    cin >> n >> d;
    while (n--) {
        int t;
        string s;
        cin >> t >> s;
        cout << process(t, s, d) << '\n';
    }
}
