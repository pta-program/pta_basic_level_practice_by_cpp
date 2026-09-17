#include <bits/stdc++.h>
using namespace std;
// 算法原理：读入时维护最高分和最低分学生，避免额外排序。
// 关键步骤：每读入一名学生就更新两个极值记录。
int main() {
    int n;
    cin >> n;
    string na, ia, nb, ib;
    int a = -1, b = 101;
    while (n--) {
        string x, y;
        int z;
        cin >> x >> y >> z;
        if (z > a)
            na = x, ia = y, a = z;
        if (z < b)
            nb = x, ib = y, b = z;
    }
    cout << na << ' ' << ia << '\n' << nb << ' ' << ib;
}
