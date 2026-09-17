#include <bits/stdc++.h>
using namespace std;
// 算法原理：先放置最小的非零数字，再按升序输出剩余数字，得到最小整数。
// 关键步骤：首位不能为 0，后续零应尽可能提前输出。
int main() {
    int c[10];
    for (int &i : c)
        cin >> i;
    int z = c[0];
    for (int i = 1; i < 10; ++i)
        if (c[i]) {
            cout << i;
            --c[i];
            break;
        }
    while (c[0]--)
        cout << 0;
    for (int i = 1; i < 10; ++i)
        while (c[i]--)
            cout << i;
}
