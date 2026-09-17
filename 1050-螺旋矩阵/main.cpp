#include <bits/stdc++.h>
using namespace std;
// 算法原理：选择行数不大于列数的因子矩阵，并用四个边界按顺时针填充。
// 关键步骤：每填完一条边就收缩对应边界，避免重复访问。
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    int c = sqrt(n);
    while (n % c)
        --c;
    int r = n / c;
    vector<vector<int>> m(r, vector<int>(c));
    int u = 0, d = r - 1, l = 0, rr = c - 1, k = 0;
    while (u <= d && l <= rr) {
        for (int j = l; j <= rr; ++j)
            m[u][j] = a[k++];
        ++u;
        for (int i = u; i <= d; ++i)
            m[i][rr] = a[k++];
        --rr;
        if (u <= d)
            for (int j = rr; j >= l; --j)
                m[d][j] = a[k++];
        --d;
        if (l <= rr)
            for (int i = d; i >= u; --i)
                m[i][l] = a[k++];
        ++l;
    }
    for (auto &row : m) {
        for (int j = 0; j < c; ++j)
            cout << (j ? " " : "") << row[j];
        cout << '\n';
    }
}
