#include <bits/stdc++.h>
using namespace std;
// 算法原理：线性扫描连续超过阈值的数据段，输出每个段的左右端点。
// 关键步骤：遇到非超标点结束当前区间，整个过程只扫描一次。
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    bool any = false;
    for (int i = 0; i < n;) {
        if (a[i] <= t) {
            ++i;
            continue;
        }
        int j = i;
        while (j + 1 < n && a[j + 1] > t)
            ++j;
        cout << '[' << i << ", " << j << "]\n";
        any = true;
        i = j + 1;
    }
    if (!any)
        cout << *max_element(a.begin(), a.end());
}
