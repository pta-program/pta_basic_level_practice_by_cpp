#include <bits/stdc++.h>
using namespace std;
// 算法原理：生成相邻斐波那契数，比较 N 到上下界的距离，等距时取较小值。
// 关键步骤：循环结束时 a<=N<=b，直接比较两侧距离即可。
int main() {
    long long n;
    cin >> n;
    long long a = 0, b = 1;
    while (b < n) {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << (n - a <= b - n ? a : b);
}
