#include <bits/stdc++.h>
using namespace std;
// 算法原理：预处理每个位置左侧最大值和右侧最小值，筛选可能的快速排序主元。
// 关键步骤：候选元素必须不小于左侧最大值且不大于右侧最小值。
int main() {
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (int &x : a)
        cin >> x;
    l[0] = a[0];
    for (int i = 1; i < n; ++i)
        l[i] = max(l[i - 1], a[i]);
    r[n - 1] = INT_MAX;
    for (int i = n - 2; i >= 0; --i)
        r[i] = min(r[i + 1], a[i]);
    vector<int> v;
    for (int i = 0; i < n; ++i)
        if (a[i] >= l[i] && a[i] <= r[i])
            v.push_back(a[i]);
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i = 0; i < (int)v.size(); ++i)
        cout << (i ? " " : "") << v[i];
}
