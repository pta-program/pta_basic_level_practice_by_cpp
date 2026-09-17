#include <bits/stdc++.h>
using namespace std;
// 算法原理：每轮将四位数字降序、升序排列后相减，直到得到 6174 或 0000。
// 关键步骤：统一补足四位，确保前导零参与运算和输出。
int main() {
    int n;
    cin >> n;
    while (1) {
        string s = to_string(n);
        s = string(4 - s.size(), '0') + s;
        string a = s, b = s;
        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());
        int x = stoi(a), y = stoi(b);
        n = x - y;
        cout << a << " - " << b << " = " << setw(4) << setfill('0') << n << '\n';
        if (n == 0 || n == 6174)
            break;
    }
}
