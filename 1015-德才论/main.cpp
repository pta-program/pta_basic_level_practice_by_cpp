#include <bits/stdc++.h>
using namespace std;
// 算法原理：先按资格和四类考生分组，再按总分、德分和准考证号排序。
// 关键步骤：分类顺序本身就是最终录取优先级。
struct S {
    string id;
    int d, c;
};
int main() {
    int n, L, H;
    cin >> n >> L >> H;
    vector<S> v[4];
    for (int i = 0; i < n; ++i) {
        S s;
        cin >> s.id >> s.d >> s.c;
        if (s.d < L || s.c < L)
            continue;
        int k = s.d >= H && s.c >= H ? 0 : s.d >= H ? 1 : s.d >= s.c ? 2 : 3;
        v[k].push_back(s);
    }
    auto cmp = [](S &a, S &b) {
        int x = a.d + a.c, y = b.d + b.c;
        return x != y ? x > y : a.d != b.d ? a.d > b.d : a.id < b.id;
    };
    cout << accumulate(begin(v), end(v), 0, [](int x, auto &z) { return x + (int)z.size(); })
         << '\n';
    for (auto &z : v) {
        sort(z.begin(), z.end(), cmp);
        for (auto &s : z)
            cout << s.id << ' ' << s.d << ' ' << s.c << '\n';
    }
}
