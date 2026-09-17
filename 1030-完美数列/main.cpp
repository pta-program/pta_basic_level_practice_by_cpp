#include <bits/stdc++.h>
using namespace std;
// 算法原理：排序后用双指针维护 a[right] <= a[left] * p 的最长窗口。
// 关键步骤：右端点只向右移动，保证整体复杂度为线性扫描。
int main() {
    int n;
    long long p;
    cin >> n >> p;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && a[j] <= a[i] * p)
            ++j;
        ans = max(ans, j - i);
    }
    cout << ans;
}
