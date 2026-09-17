#include <bits/stdc++.h>
using namespace std;
// 算法原理：逐项扫描上一项的连续字符段，输出“次数+字符”形成下一项。
// 关键步骤：双指针找到每个连续段的结束位置。
int main() {
    string s;
    int n;
    cin >> s >> n;
    while (--n) {
        string t;
        for (int i = 0; i < (int)s.size();) {
            int j = i + 1;
            while (j < (int)s.size() && s[j] == s[i])
                ++j;
            t += s[i];
            t += to_string(j - i);
            i = j;
        }
        s = t;
    }
    cout << s;
}
