#include <bits/stdc++.h>
using namespace std;
// 算法原理：按题目权重计算前 17 位校验和，并与校验码表比对。
// 关键步骤：同时检查前 17 位是否为数字以及最后一位校验码。
int main() {
    int n;
    cin >> n;
    int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char z[] = "10X98765432";
    bool all = true;
    while (n--) {
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < 17; ++i)
            sum += (s[i] - '0') * w[i];
        if (!isdigit((unsigned char)s[17]) || z[sum % 11] != s[17])
            cout << s << '\n', all = false;
    }
    if (all)
        cout << "All passed";
}
