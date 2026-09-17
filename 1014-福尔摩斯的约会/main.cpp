#include <bits/stdc++.h>
using namespace std;
// 算法原理：依次寻找两对字符串的首个有效公共字符，解码星期、小时和分钟。
// 关键步骤：第二个公共字符必须出现在星期字符之后。
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    string day = "MON TUE WED THU FRI SAT SUN";
    int pos = -1, h = -1, m = -1;
    for (int i = 0; i < (int)min(a.size(), b.size()); ++i)
        if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
            pos = i;
            break;
        }
    for (int i = pos + 1; i < (int)min(a.size(), b.size()); ++i)
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || (a[i] >= '0' && a[i] <= '9'))) {
            h = a[i] >= 'A' ? a[i] - 'A' + 10 : a[i] - '0';
            break;
        }
    for (int i = 0; i < (int)min(c.size(), d.size()); ++i)
        if (c[i] == d[i] && isalpha((unsigned char)c[i])) {
            m = i;
            break;
        }
    cout << day.substr((a[pos] - 'A') * 4, 3) << ' ' << setw(2) << setfill('0') << h << ':'
         << setw(2) << m;
}
