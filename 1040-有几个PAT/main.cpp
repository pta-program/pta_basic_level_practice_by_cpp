#include <bits/stdc++.h>
using namespace std;
// 算法原理：扫描字符串维护 P 数量和 PA 子序列数量，遇到 T 累加答案。
// 关键步骤：所有计数都对 1e9+7 取模，防止结果溢出。
int main() {
    string s;
    cin >> s;
    long long p = 0, pa = 0, ans = 0;
    for (char c : s) {
        if (c == 'P')
            ++p;
        else if (c == 'A')
            pa = (pa + p) % 1000000007;
        else if (c == 'T')
            ans = (ans + pa) % 1000000007;
    }
    cout << ans;
}
