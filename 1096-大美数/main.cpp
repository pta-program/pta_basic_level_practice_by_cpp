#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举正因数集合中的四个不同因数，检查其和是否能被 N 整除。
// 关键步骤：四层下标递增保证四个因数互不相同且不重复枚举。
int main() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> d;
        for (int i = 1; i <= n; ++i)
            if (n % i == 0)
                d.push_back(i);
        bool ok = 0;
        for (int a = 0; a < (int)d.size(); ++a)
            for (int b = a + 1; b < (int)d.size(); ++b)
                for (int c = b + 1; c < (int)d.size(); ++c)
                    for (int e = c + 1; e < (int)d.size(); ++e)
                        if ((d[a] + d[b] + d[c] + d[e]) % n == 0)
                            ok = 1;
        cout << (ok ? "Yes" : "No") << '\n';
    }
}
