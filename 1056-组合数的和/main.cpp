#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举两个不同下标的数字，累加所有有序二位组合。
// 关键步骤：i 和 j 必须不同，因此每个数字不能与自身组合。
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    long long s = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j)
                s += 10 * a[i] + a[j];
    cout << s;
}
