#include <bits/stdc++.h>
using namespace std;
// 算法原理：用字符串流拆分单词，再从后向前输出。
// 关键步骤：字符串流自动忽略连续空格并保留单词顺序信息。
int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> a;
    while (ss >> s)
        a.push_back(s);
    for (int i = a.size() - 1; i >= 0; --i) {
        if (i != (int)a.size() - 1)
            cout << ' ';
        cout << a[i];
    }
}
