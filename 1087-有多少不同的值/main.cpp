#include <bits/stdc++.h>
using namespace std;
// 算法原理：枚举 1 到 N 计算 floor(n/2)+floor(n/3)+floor(n/5)，用集合去重。
// 关键步骤：整数除法天然实现三个 floor 运算。
int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i / 2 + i / 3 + i / 5);
    cout << s.size();
}
