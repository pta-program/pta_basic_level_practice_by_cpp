#include <bits/stdc++.h>
using namespace std;
// 算法原理：解析每道选择题答案集合，完全匹配得分并统计答错次数最多的题目。
// 关键步骤：括号中的选项先读入 set，再与标准答案集合比较。
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> score(m), wrong(m);
    vector<set<char>> key(m);
    for (int i = 0; i < m; ++i) {
        int num, k;
        cin >> score[i] >> num >> k;
        while (k--) {
            char c;
            cin >> c;
            key[i].insert(c);
        }
    }
    for (int i = 0; i < n; ++i) {
        int total = 0;
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
            if (x == key[j])
                total += score[j];
            else
                ++wrong[j];
        }
        cout << total << '\n';
    }
    int mx = *max_element(wrong.begin(), wrong.end());
    if (!mx)
        cout << "Too simple";
    else {
        cout << mx;
        for (int i = 0; i < m; ++i)
            if (wrong[i] == mx) {
                cout << ' ' << i + 1;
            }
    }
}
