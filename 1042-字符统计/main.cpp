#include <bits/stdc++.h>
using namespace std;
// 算法原理：忽略非字母并统一转小写，用频数统计后按字母序取最优解。
// 关键步骤：比较器在频数相等时选择字典序更小的字母。
int main() {
    string s;
    getline(cin, s);
    map<char, int> c;
    for (char x : s)
        if (isalpha((unsigned char)x))
            ++c[tolower((unsigned char)x)];
    auto p = max_element(c.begin(), c.end(), [](auto &a, auto &b) {
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    });
    cout << p->first << ' ' << p->second;
}
