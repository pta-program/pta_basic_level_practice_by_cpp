#include <bits/stdc++.h>
using namespace std;
// 算法原理：按百位、十位、个位分别输出对应数量的 B、S 和数字字符。
// 关键步骤：使用字符串重复构造百位和十位部分。
int main() {
    int n;
    cin >> n;
    cout << string(n / 100, 'B') << string(n / 10 % 10, 'S');
    for (int i = 1; i <= n % 10; ++i)
        cout << i;
}
