#include <bits/stdc++.h>
using namespace std;
// 算法原理：计算每个数字各位和，将结果放入集合去重后排序输出。
// 关键步骤：set 同时完成去重和升序遍历。
int main() {
    int n;
    cin >> n;
    set<int> s;
    while (n--) {
        string x;
        cin >> x;
        int z = 0;
        for (char c : x)
            z += c - '0';
        s.insert(z);
    }
    cout << s.size() << '\n';
    int i = 0;
    for (int x : s)
        cout << (i++ ? " " : "") << x;
}
