#include <bits/stdc++.h>
using namespace std;
// 算法原理：比较双方喊出的数字和手势，分别统计甲乙输赢次数。
// 关键步骤：两人喊数相等时跳过，只有一方猜中时更新胜负。
int main() {
    int n, a, b, c, d, x = 0, y = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> d;
        int sum = a + c;
        if (sum == b && sum == d)
            continue;
        if (sum == b)
            ++y;
        else if (sum == d)
            ++x;
    }
    cout << x << ' ' << y;
}
