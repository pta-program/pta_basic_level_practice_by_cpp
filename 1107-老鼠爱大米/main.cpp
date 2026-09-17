#include <bits/stdc++.h>
using namespace std;
// 算法原理：取每组老鼠中的最大体重，再在各组冠军中寻找全局最大值。
// 关键步骤：第一行输出每组冠军，第二行输出全局冠军。
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> win(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0, x; j < m; ++j)
            cin >> x, win[i] = max(win[i], x);
    }
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (win[i] > win[best])
            best = i;
    for (int i = 0; i < n; ++i)
        cout << (i ? " " : "") << win[i];
    cout << '\n' << win[best];
}
