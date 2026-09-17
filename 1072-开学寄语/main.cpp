#include <bits/stdc++.h>
using namespace std;
// 算法原理：用集合保存违禁物品，逐个学生筛选并统计查缴人数和件数。
// 关键步骤：同一学生携带同一违禁物品多次时按件数全部统计。
int main() {
    int n, m;
    cin >> n >> m;
    set<string> x;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        x.insert(s);
    }
    int stu = 0, item = 0;
    for (int i = 0; i < n; ++i) {
        string name;
        int k;
        cin >> name >> k;
        vector<string> bad;
        while (k--) {
            string s;
            cin >> s;
            if (x.count(s))
                bad.push_back(s);
        }
        if (!bad.empty()) {
            ++stu;
            item += bad.size();
            cout << name << ":";
            for (auto &s : bad)
                cout << ' ' << s;
            cout << '\n';
        }
    }
    cout << stu << ' ' << item;
}
