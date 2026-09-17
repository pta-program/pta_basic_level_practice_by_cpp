#include <bits/stdc++.h>
using namespace std;
// 算法原理：按 A、B 的拼接顺序扫描，用布尔数组保证每个字符只输出一次。
// 关键步骤：可见 ASCII 码范围固定，因此用 128 大小数组即可。
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool seen[128] = {};
    for (char c : a + b)
        if (!seen[(unsigned char)c])
            cout << c, seen[(unsigned char)c] = 1;
}
