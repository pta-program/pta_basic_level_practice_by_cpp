#include <bits/stdc++.h>
using namespace std;
// 算法原理：判断 N 与 N±6 是否构成素数对，否则向上寻找下一个性感素数端点。
// 关键步骤：优先检查 N-6，再检查 N+6，符合题目输出约定。
bool p(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    if (p(n) && p(n - 6))
        cout << "Yes\n" << n - 6;
    else if (p(n) && p(n + 6))
        cout << "Yes\n" << n + 6;
    else {
        cout << "No\n";
        for (int i = n + 1;; ++i)
            if (p(i) && (p(i - 6) || p(i + 6))) {
                cout << i;
                break;
            }
    }
}
