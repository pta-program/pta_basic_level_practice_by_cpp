#include <bits/stdc++.h>
using namespace std;
// 算法原理：压缩时合并连续相同字符，解压时读取数字前缀并重复字符。
// 关键步骤：没有数字前缀时默认重复 1 次。
int main() {
    char op;
    string s;
    cin >> op;
    getline(cin, s);
    getline(cin, s);
    if (op == 'C') {
        for (int i = 0; i < (int)s.size();) {
            int j = i + 1;
            while (j < (int)s.size() && s[j] == s[i])
                ++j;
            if (j - i > 1)
                cout << j - i;
            cout << s[i];
            i = j;
        }
    } else {
        for (int i = 0; i < (int)s.size();) {
            int k = 0;
            while (i < (int)s.size() && isdigit((unsigned char)s[i]))
                k = k * 10 + s[i++] - '0';
            if (i < (int)s.size()) {
                if (!k)
                    k = 1;
                cout << string(k, s[i++]);
            }
        }
    }
}
