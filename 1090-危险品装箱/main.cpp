#include <bits/stdc++.h>
using namespace std;
// 算法原理：把不相容关系存为双向集合，检查清单中任意两件物品是否冲突。
// 关键步骤：只要发现一对冲突物品即可判定当前清单为 No。
int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> bad;
    for (int i = 0, a, b; i < n; ++i)
        cin >> a >> b, bad.insert({a, b}), bad.insert({b, a});
    while (m--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int &x : a)
            cin >> x;
        bool ok = 1;
        for (int i = 0; i < k; ++i)
            for (int j = i + 1; j < k; ++j)
                if (bad.count({a[i], a[j]}))
                    ok = 0;
        cout << (ok ? "Yes" : "No") << '\n';
    }
}
