#include <bits/stdc++.h>
using namespace std;
// 算法原理：动态维护每个 P 前缀作为子序列的最早起点，扫描结束位置求最短窗口。
// 关键步骤：倒序更新 dp，保证本轮不会重复使用同一字符。
int main() {
    string s, p;
    cin >> s >> p;
    vector<int> dp(p.size(), -1);
    int best = INT_MAX, st = 0;
    for (int i = 0; i < (int)s.size(); ++i)
        for (int j = p.size() - 1; j >= 0; --j)
            if (s[i] == p[j]) {
                dp[j] = j ? dp[j - 1] : i;
                if (j == (int)p.size() - 1 && dp[j] >= 0) {
                    int len = i - dp[j] + 1;
                    if (len < best)
                        best = len, st = dp[j];
                }
            }
    cout << s.substr(st, best);
}
