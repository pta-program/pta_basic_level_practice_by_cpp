#include <bits/stdc++.h>
using namespace std;
// 算法原理：检查字符集合、P/T 唯一性及 A 的数量关系 left * middle == right。
// 关键步骤：分别统计 P 前、P 与 T 间、T 后的 A 数量。
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int p = s.find('P'), t = s.find('T');
        bool ok = p != string::npos && t != string::npos && t > p + 1;
        for (char c : s)
            if (c != 'P' && c != 'A' && c != 'T')
                ok = false;
        if (ok) {
            int a = p, b = t - p - 1, c = s.size() - t - 1;
            ok = a * b == c;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
