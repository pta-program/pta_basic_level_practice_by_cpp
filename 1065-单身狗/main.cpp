#include <bits/stdc++.h>
using namespace std;
// 算法原理：建立伴侣双向映射，筛选在场且伴侣不在场的单身者。
// 关键步骤：结果按编号升序排列并按五位格式输出。
int main() {
    int n;
    cin >> n;
    map<int, int> p;
    for (int i = 0, a, b; i < n; ++i)
        cin >> a >> b, p[a] = b, p[b] = a;
    int m;
    cin >> m;
    vector<int> a(m);
    set<int> s;
    for (int &x : a)
        cin >> x, s.insert(x);
    vector<int> v;
    for (int x : a)
        if (!p.count(x) || !s.count(p[x]))
            v.push_back(x);
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i = 0; i < (int)v.size(); ++i)
        cout << (i ? " " : "") << setw(5) << setfill('0') << v[i];
}
