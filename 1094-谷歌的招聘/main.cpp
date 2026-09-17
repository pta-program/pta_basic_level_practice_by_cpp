#include <bits/stdc++.h>
using namespace std;
// 算法原理：按起点从左到右枚举 K 位窗口，找到最早出现的素数。
// 关键步骤：保留窗口字符串输出，确保原始前导零不丢失。
bool prime(long long x) {
    if (x < 2)
        return false;
    for (long long i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
int main() {
    int l, k;
    string s;
    cin >> l >> k >> s;
    for (int i = 0; i + k <= l; ++i) {
        string t = s.substr(i, k);
        if (prime(stoll(t))) {
            cout << t;
            return 0;
        }
    }
    cout << 404;
}
