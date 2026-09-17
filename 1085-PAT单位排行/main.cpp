#include <bits/stdc++.h>
using namespace std;
// 算法原理：按学校累加三种级别的加权分数，按总分、人数和名称排序排名。
// 关键步骤：用放大 6 倍的整数分数避免 1.5 和 1/1.5 的浮点误差。
struct S {
    string n;
    long long score;
    int cnt;
};
int main() {
    int n;
    cin >> n;
    map<string, S> a;
    for (int i = 0; i < n; ++i) {
        string id, sch;
        int x;
        cin >> id >> x >> sch;
        for (char &c : sch)
            c = tolower((unsigned char)c);
        a[sch].n = sch;
        ++a[sch].cnt;
        if (id[0] == 'B')
            a[sch].score += 4LL * x;
        else if (id[0] == 'A')
            a[sch].score += 6LL * x;
        else
            a[sch].score += 9LL * x;
    }
    vector<S> v;
    for (auto &[x, s] : a)
        v.push_back(s);
    sort(v.begin(), v.end(), [](S &a, S &b) {
        return a.score / 6 != b.score / 6 ? a.score / 6 > b.score / 6
               : a.cnt != b.cnt           ? a.cnt < b.cnt
                                          : a.n < b.n;
    });
    cout << v.size() << '\n';
    for (int i = 0, rank = 0; i < (int)v.size(); ++i) {
        if (i == 0 || v[i].score / 6 != v[i - 1].score / 6)
            rank = i + 1;
        cout << rank << ' ' << v[i].n << ' ' << v[i].score / 6 << ' ' << v[i].cnt << '\n';
    }
}
