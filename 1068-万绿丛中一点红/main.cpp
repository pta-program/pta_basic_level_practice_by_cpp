#include <bits/stdc++.h>
using namespace std;
// 算法原理：先找全图唯一颜色，再检查其八邻域是否都超过色差阈值。
// 关键步骤：分别处理不存在、唯一和多个候选点三种结果。
int main() {
    int m, n, t;
    cin >> m >> n >> t;
    vector<vector<int>> a(n, vector<int>(m));
    map<int, int> cnt;
    for (auto &r : a)
        for (int &x : r)
            cin >> x, ++cnt[x];
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (cnt[a[i][j]] == 1) {
                bool ok = true;
                for (int x = max(0, i - 1); x <= min(n - 1, i + 1); ++x)
                    for (int y = max(0, j - 1); y <= min(m - 1, j + 1); ++y)
                        if ((x != i || y != j) && abs(a[x][y] - a[i][j]) <= t)
                            ok = false;
                if (ok)
                    v.push_back({j + 1, i + 1, a[i][j]});
            }
    if (v.size() == 1) {
        auto [x, y, c] = v[0];
        cout << '(' << x << ", " << y << "): " << c;
    } else if (v.empty())
        cout << "Not Exist";
    else
        cout << "Not Unique";
}
