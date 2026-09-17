#include <bits/stdc++.h>
using namespace std;
// 算法原理：水平管道直径受最小顶部高度减最大底部高度限制。
// 关键步骤：使用全局最小顶部和全局最大底部计算所有截面的共同空间。
int main() {
    int n;
    cin >> n;
    vector<int> top(n), bot(n);
    for (int &x : top)
        cin >> x;
    for (int &x : bot)
        cin >> x;
    int d = *min_element(top.begin(), top.end()) - *max_element(bot.begin(), bot.end());
    if (d >= 1)
        cout << "Yes " << d;
    else
        cout << "No " << 1 - d;
}
