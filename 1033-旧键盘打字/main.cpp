#include <bits/stdc++.h>
using namespace std;
// 算法原理：建立坏键集合，过滤坏字符以及因“+”键失效而无法输入的大写字母。
// 关键步骤：输出字符串按原顺序扫描，不改变有效字符顺序。
int main() {
    string bad, s;
    getline(cin, bad);
    getline(cin, s);
    set<char> x(bad.begin(), bad.end());
    for (char c : s) {
        char upper = isalpha((unsigned char)c) ? toupper((unsigned char)c) : c;
        bool blocked = x.count(c) || x.count(upper);
        if (isupper((unsigned char)c) && x.count('+'))
            blocked = true;
        if (!blocked)
            cout << c;
    }
}
