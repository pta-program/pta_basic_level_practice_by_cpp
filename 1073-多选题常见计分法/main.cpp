#include <bits/stdc++.h>
using namespace std;
// 算法原理：答案完全匹配得满分、为正确答案子集得半分，并统计集合对称差中的选项。
// 关键步骤：对称差同时覆盖多选错选和漏选两类错误。
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> score(m);
    vector<set<char>> key(m);
    vector<vector<int>> bad(m, vector<int>(5));
    for (int i = 0; i < m; ++i) {
        int full, num, k;
        cin >> full >> num >> k;
        score[i] = full;
        while (k--) {
            char c;
            cin >> c;
            key[i].insert(c);
        }
    }
    for (int i = 0; i < n; ++i) {
        double total = 0;
        for (int j = 0; j < m; ++j) {
            char ch;
            int k;
            cin >> ch >> k;
            set<char> x;
            while (k--) {
                cin >> ch;
                x.insert(ch);
            }
            cin >> ch;
            for (char c : x)
                if (!key[j].count(c))
                    ++bad[j][c - 'a'];
            for (char c : key[j])
                if (!x.count(c))
                    ++bad[j][c - 'a'];
            if (x == key[j])
                total += score[j];
            else if (includes(key[j].begin(), key[j].end(), x.begin(), x.end()))
                total += score[j] / 2.0;
        }
        cout << fixed << setprecision(1) << total << '\n';
    }
    int mx = 0;
    for (auto &v : bad)
        for (int x : v)
            mx = max(mx, x);
    if (!mx)
        cout << "Too simple";
    else {
        bool first = true;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < 5; ++j)
                if (bad[i][j] == mx) {
                    if (!first)
                        cout << '\n';
                    cout << mx << ' ' << i + 1 << '-' << char('a' + j);
                    first = false;
                }
    }
}
