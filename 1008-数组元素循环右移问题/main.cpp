#include <bits/stdc++.h>
using namespace std;
// 算法原理：利用 rotate 将末尾 M 个元素整体移动到数组开头。
// 关键步骤：先对 M 取模，再进行原地旋转。
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    m %= n;
    rotate(a.begin(), a.end() - m, a.end());
    for (int i = 0; i < n; ++i) {
        if (i)
            cout << ' ';
        cout << a[i];
    }
}
