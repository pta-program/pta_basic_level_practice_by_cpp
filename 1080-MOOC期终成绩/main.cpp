#include <bits/stdc++.h>
using namespace std;
// 算法原理：合并三类成绩，计算期末/期中加权总评，筛选合格者后排序。
// 关键步骤：期末高于期中时直接采用期末，否则使用 40%+60% 公式。
struct S {
    string id;
    int p = -1, m = -1, f = -1, total;
};
int main() {
    int P, M, N;
    cin >> P >> M >> N;
    map<string, S> a;
    for (int i = 0; i < P; ++i) {
        string id;
        int x;
        cin >> id >> x;
        a[id].id = id;
        a[id].p = x;
    }
    for (int i = 0; i < M; ++i) {
        string id;
        int x;
        cin >> id >> x;
        a[id].id = id;
        a[id].m = x;
    }
    for (int i = 0; i < N; ++i) {
        string id;
        int x;
        cin >> id >> x;
        a[id].id = id;
        a[id].f = x;
    }
    vector<S> v;
    for (auto &[id, s] : a)
        if (s.p >= 200 && s.f >= 0) {
            s.total = round(s.m > s.f ? s.m * .4 + s.f * .6 : s.f);
            if (s.total >= 60)
                v.push_back(s);
        }
    sort(v.begin(), v.end(),
         [](S &a, S &b) { return a.total != b.total ? a.total > b.total : a.id < b.id; });
    for (auto &s : v)
        cout << s.id << ' ' << s.p << ' ' << s.m << ' ' << s.f << ' ' << s.total << '\n';
}
