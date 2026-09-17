#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举两名狼人，统计陈述真假，要求恰有两名说谎者且其中一名是狼人。
// 关键步骤：正号表示声称目标是好人，负号表示声称目标是狼人。
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int w1 = 1; w1 <= n; ++w1)
        for (int w2 = w1 + 1; w2 <= n; ++w2) {
            int lie = 0, inwolf = 0;
            for (int i = 1; i <= n; ++i) {
                bool wolf = i == w1 || i == w2;
                bool claimed = a[i] < 0, actual = abs(a[i]) == w1 || abs(a[i]) == w2;
                if (claimed != actual) {
                    ++lie;
                    if (wolf)
                        ++inwolf;
                }
            }
            if (lie == 2 && inwolf == 1) {
                cout << w1 << ' ' << w2;
                return 0;
            }
        }
    cout << "No Solution";
}
