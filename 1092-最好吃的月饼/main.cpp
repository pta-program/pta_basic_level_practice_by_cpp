#include <bits/stdc++.h>
using namespace std;
// 算法原理：按种类累加各城市销量，再输出最大销量及所有并列种类。
// 关键步骤：遍历销量数组时按编号递增自然满足并列输出顺序。
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0, x; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> x, a[j] += x;
    int mx = *max_element(a.begin(), a.end());
    cout << mx << '\n';
    bool f = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == mx) {
            if (f)
                cout << ' ';
            cout << i + 1;
            f = 1;
        }
}
