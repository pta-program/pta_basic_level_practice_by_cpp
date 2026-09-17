#include <bits/stdc++.h>
using namespace std;
// 算法原理：从完整日期到最后一位依次取后缀，逐个判断对应整数是否为素数。
// 关键步骤：输出保留原始字符串的后缀，前导零只影响显示不影响数值判断。
bool prime(long long x) {
    if (x < 2)
        return false;
    for (long long i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
int main() {
    string s;
    cin >> s;
    bool all = true;
    for (int len = s.size(); len >= 1; --len) {
        string t = s.substr(s.size() - len);
        bool ok = prime(stoll(t));
        cout << t << ' ' << (ok ? "Yes" : "No") << '\n';
        all &= ok;
    }
    if (all)
        cout << "All Prime!";
}
