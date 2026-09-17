#include <bits/stdc++.h>
using namespace std;
// 算法原理：解析三行方括号符号集合，按五个下标拼接表情模板。
// 关键步骤：先验证五个下标均在对应集合范围内，再访问元素。
vector<string> get() {
    string s;
    getline(cin, s);
    vector<string> v;
    for (int i = 0; i < (int)s.size(); ++i)
        if (s[i] == '[') {
            int j = s.find(']', i);
            if (j != string::npos)
                v.push_back(s.substr(i + 1, j - i - 1)), i = j;
        }
    return v;
}
int main() {
    vector<string> h = get(), e = get(), m = get();
    int k;
    cin >> k;
    while (k--) {
        int a, b, c, d, f;
        cin >> a >> b >> c >> d >> f;
        if (a > h.size() || b > e.size() || c > m.size() || d > e.size() || f > h.size())
            cout << "Are you kidding me? @\\/@";
        else
            cout << h[a - 1] << '(' << e[b - 1] << m[c - 1] << e[d - 1] << ')' << h[f - 1];
        if (k)
            cout << '\n';
    }
}
