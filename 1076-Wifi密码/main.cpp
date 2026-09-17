#include <bits/stdc++.h>
using namespace std;
// 算法原理：每道题四个选项中找到标记为 T 的选项，拼接其编号。
// 关键步骤：选项编号从 1 开始，标记字符 T 的首字符就是答案编号。
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            string s;
            cin >> s;
            if (s.back() == 'T')
                cout << s[0] - 'A' + 1;
        }
    }
}
