#include <bits/stdc++.h>
using namespace std;
// 算法原理：将里程降序排列，寻找第 i 天里程严格大于 i 的最大 i。
// 关键步骤：排序后第 i 个元素对应前 i+1 天的候选阈值。
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n && a[i] > i + 1; ++i)
        ans = i + 1;
    cout << ans;
}
