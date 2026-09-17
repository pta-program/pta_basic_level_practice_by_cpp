#include <bits/stdc++.h>
using namespace std;
// 算法原理：用频次数组统计每个成绩，再 O(1) 回答查询。
// 关键步骤：成绩范围固定为 0 到 100，因此数组索引安全且高效。
int main() {
    int n;
    cin >> n;
    vector<int> c(101);
    for (int i = 0, x; i < n; ++i)
        cin >> x, ++c[x];
    int k;
    cin >> k;
    for (int i = 0, x; i < k; ++i) {
        cin >> x;
        cout << (i ? " " : "") << c[x];
    }
}
