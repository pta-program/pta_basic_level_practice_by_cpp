#include <bits/stdc++.h>
using namespace std;
// 算法原理：从左到右构造每个前缀，检查长度为 i 的前缀是否能被 i 整除。
// 关键步骤：前缀值通过 prev*10+digit 增量构造，避免重复转换。
int main() {
    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        string s = to_string(x);
        bool ok = true;
        long long p = 0;
        for (int i = 0; i < (int)s.size() && ok; ++i) {
            p = p * 10 + s[i] - '0';
            if (i && p % (i + 1))
                ok = false;
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}
