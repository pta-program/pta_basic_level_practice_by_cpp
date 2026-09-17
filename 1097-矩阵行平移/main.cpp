#include <bits/stdc++.h>
using namespace std;
// 算法原理：读取矩阵时直接把奇数行按周期右移后的值累加到列和。
// 关键步骤：第 i 个奇数行的右移量为 (i/2)%k+1。
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<long long> sum(n);
    for (int i = 0; i < n; ++i) {
        vector<int> a(n);
        for (int &z : a)
            cin >> z;
        if (i % 2 == 0) {
            int sh = (i / 2) % k + 1;
            for (int j = 0; j < n; ++j)
                sum[j] += j < sh ? x : a[j - sh];
        } else
            for (int j = 0; j < n; ++j)
                sum[j] += a[j];
    }
    for (int i = 0; i < n; ++i)
        cout << (i ? " " : "") << sum[i];
}
