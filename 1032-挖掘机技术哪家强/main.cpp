#include <bits/stdc++.h>
using namespace std;
// 算法原理：用哈希表累加各校区成绩，再取总分最大者。
// 关键步骤：map 的键为校区编号，值为该校区累计成绩。
int main() {
    int n;
    cin >> n;
    map<int, int> s;
    for (int i = 0, x, y; i < n; ++i)
        cin >> x >> y, s[x] += y;
    auto p = max_element(s.begin(), s.end(), [](auto &a, auto &b) { return a.second < b.second; });
    cout << p->first << ' ' << p->second;
}
