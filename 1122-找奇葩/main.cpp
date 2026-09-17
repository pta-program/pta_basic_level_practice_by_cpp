#include <bits/stdc++.h>
using namespace std;
// 算法原理：奇数出现偶数次，所有奇数异或后只剩下出现奇数次的目标值。
// 关键步骤：偶数不参与异或，避免其出现次数影响答案。
int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x % 2)
            ans ^= x;
    }
    cout << ans;
}
