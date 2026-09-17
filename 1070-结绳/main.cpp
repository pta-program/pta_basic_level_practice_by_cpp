#include <bits/stdc++.h>
using namespace std;
// 算法原理：每次把当前绳长与下一段取平均；先合并短绳可使总长度最大。
// 关键步骤：排序后从短到长依次合并，最后向下取整。
int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    double x = a[0];
    for (int i = 1; i < n; ++i)
        x = (x + a[i]) / 2;
    cout << (int)x;
}
