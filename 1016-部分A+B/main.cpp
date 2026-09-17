#include <bits/stdc++.h>
using namespace std;
// 算法原理：扫描两个字符串，提取指定数字组成的新数后求和。
// 关键步骤：通过十进制累加自然处理重复出现的指定数字。
int main() {
    string a, b;
    char da, db;
    cin >> a >> da >> b >> db;
    long long x = 0, y = 0;
    for (char c : a)
        if (c == da)
            x = x * 10 + c - '0';
    for (char c : b)
        if (c == db)
            y = y * 10 + c - '0';
    cout << x + y;
}
