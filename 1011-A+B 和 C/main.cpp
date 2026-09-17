#include <bits/stdc++.h>
using namespace std;
// 算法原理：使用 long long 计算 A+B，并逐组判断其是否大于 C。
// 关键步骤：按题目要求输出 Case #i 和小写布尔结果。
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i << ": " << (a + b > c ? "true" : "false") << '\n';
    }
}
