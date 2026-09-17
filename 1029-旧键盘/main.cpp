#include <bits/stdc++.h>
using namespace std;
// 算法原理：双指针比较原字符串和正确字符串，记录首次发现的坏键并去重输出。
// 关键步骤：坏键集合统一保存为大写，合并大小写字母的故障状态。
int main() {
    string a, b;
    cin >> a >> b;
    set<char> bad;
    int j = 0;
    for (char c : a) {
        if (j < (int)b.size() && c == b[j])
            ++j;
        else
            bad.insert(toupper(c));
    }
    for (char c : a)
        if (bad.count(toupper(c))) {
            cout << char(toupper(c));
            bad.erase(toupper(c));
        }
}
