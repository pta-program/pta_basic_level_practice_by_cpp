#include <bits/stdc++.h>
using namespace std;
// 算法原理：把日期转换为固定八位 yyyymmdd 字符串，与其逆序串比较。
// 关键步骤：年份、月份和日期分别补足 4、2、2 位。
int main() {
    map<string, int> mp;
    string x[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; ++i)
        mp[x[i]] = i + 1;
    int n;
    cin >> n;
    while (n--) {
        string mon, day, year;
        cin >> mon >> day >> year;
        day.pop_back();
        int y = stoi(year), d = stoi(day), mo = mp[mon];
        ostringstream o;
        o << setw(4) << setfill('0') << y << setw(2) << mo << setw(2) << d;
        string s = o.str(), r = s;
        reverse(r.begin(), r.end());
        cout << (s == r ? 'Y' : 'N') << ' ' << s << '\n';
    }
}
