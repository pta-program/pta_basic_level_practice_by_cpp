#include <bits/stdc++.h>
using namespace std;
// 算法原理：反复执行各位立方乘积的数位和，直到结果不再变化，再统计最终个位数的频数。
// 关键步骤：对区间内每个数字独立迭代，最后按出现次数取并列结果。
long long f(long long x) {
    vector<int> product(1, 1);
    if (!x)
        return 0;
    while (x) {
        int d = x % 10;
        x /= 10;
        int factor = d * d * d;
        int carry = 0;
        for (int &digit : product) {
            int value = digit * factor + carry;
            digit = value % 10;
            carry = value / 10;
        }
        while (carry) {
            product.push_back(carry % 10);
            carry /= 10;
        }
    }
    int s = 0;
    for (int digit : product)
        s += digit;
    return s;
}
int main() {
    int a, b;
    cin >> a >> b;
    int c[10] = {};
    for (int x = a; x <= b; ++x) {
        long long y = x;
        while (true) {
            long long next = f(y);
            if (next == y)
                break;
            y = next;
        }
        ++c[y];
    }
    int mx = *max_element(c, c + 10);
    cout << mx << '\n';
    bool first = true;
    for (int i = 0; i < 10; ++i)
        if (c[i] == mx) {
            if (!first)
                cout << ' ';
            cout << i;
            first = false;
        }
}
