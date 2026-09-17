#include <bits/stdc++.h>
using namespace std;
// 算法原理：大小写不敏感地累加字母序号，再统计二进制表示中的 0 和 1。
// 关键步骤：不输出二进制表示的前导零。
int main() {
    string s;
    getline(cin, s);
    int sum = 0;
    for (char c : s)
        if (isalpha((unsigned char)c))
            sum += tolower((unsigned char)c) - 'a' + 1;
    int one = __builtin_popcount((unsigned)sum),
        zero = sum ? 32 - __builtin_clz((unsigned)sum) - one : 0;
    cout << zero << ' ' << one;
}
