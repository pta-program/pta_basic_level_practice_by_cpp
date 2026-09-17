#include <bits/stdc++.h>
using namespace std;
// 算法原理：从首个中奖位置开始按间隔跳转，已中奖昵称则顺延并用集合去重。
// 关键步骤：中奖后按 N 跳跃，重复昵称只递增当前位置直到找到新人。
int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<string> a(m);
    for (auto &x : a)
        cin >> x;
    set<string> used;
    bool any = false;
    for (int i = s - 1; i < m;) {
        if (!used.count(a[i])) {
            cout << a[i] << '\n';
            used.insert(a[i]);
            any = true;
            i += n;
        } else
            ++i;
    }
    if (!any)
        cout << "Keep going...";
}
