#include <bits/stdc++.h>
using namespace std;
// 算法原理：统计六种字符，每轮按 PATest 顺序输出仍有库存的字符。
// 关键步骤：循环持续到六个字符的剩余计数全部归零。
int main() {
    string s;
    cin >> s;
    int c[6] = {};
    for (char x : s) {
        int p = string("PATest").find(x);
        if (p >= 0)
            ++c[p];
    }
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 0; i < 6; ++i)
            if (c[i])
                cout << "PATest"[i], --c[i], ok = true;
    }
}
