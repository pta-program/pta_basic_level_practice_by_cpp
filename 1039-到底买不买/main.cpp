#include <bits/stdc++.h>
using namespace std;
// 算法原理：统计已有珠子数量，逐个消耗目标珠子并计算缺少或剩余数量。
// 关键步骤：缺少任意一种珠子即输出 No，否则输出剩余总数。
int main() {
    string a, b;
    cin >> a >> b;
    int c[128] = {};
    for (char x : a)
        ++c[(int)x];
    int lack = 0;
    for (char x : b)
        if (c[(int)x])
            --c[(int)x];
        else
            ++lack;
    if (lack)
        cout << "No " << lack;
    else
        cout << "Yes " << a.size() - b.size();
}
