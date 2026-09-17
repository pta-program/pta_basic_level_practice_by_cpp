#include <bits/stdc++.h>
using namespace std;
// 算法原理：正价格保证单调性，用滑动窗口统计和不超过现金的连续区间数量。
// 关键步骤：右端点扩展后不断移动左端点，窗口内每个结尾贡献窗口长度。
int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    long long sum = 0, ans = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (sum > m && l <= r)
            sum -= a[l++];
        ans += r - l + 1;
    }
    cout << ans;
}
