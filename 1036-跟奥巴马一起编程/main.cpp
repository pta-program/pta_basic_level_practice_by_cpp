#include <bits/stdc++.h>
using namespace std;
// 算法原理：字符矩形宽为 N，高为 (N+1)/2，逐行输出即可。
// 关键步骤：行数使用整数上取整，避免奇数宽度丢失一行。
int main() {
    int n;
    char c;
    cin >> n >> c;
    int r = (n + 1) / 2;
    for (int i = 0; i < r; ++i) {
        if (i == 0 || i == r - 1) {
            for (int j = 0; j < n; ++j)
                cout << c;
        } else {
            cout << c;
            for (int j = 0; j < n - 2; ++j)
                cout << ' ';
            cout << c;
        }
        cout << '\n';
    }
}
