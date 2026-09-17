#include <bits/stdc++.h>
using namespace std;
// 算法原理：逐局检查下注额度，再根据大小判断增减筹码并处理游戏结束。
// 关键步骤：下注超过当前余额不改变余额，输光后立即停止处理。
int main() {
    int total, k;
    cin >> total >> k;
    while (k--) {
        int n1, b, t, n2;
        cin >> n1 >> b >> t >> n2;
        if (!total) {
            cout << "Game Over.";
            break;
        }
        if (t > total) {
            cout << "Not enough tokens.  Total = " << total << '.';
        } else if ((n2 > n1) == b) {
            total += t;
            cout << "Win " << t << "!  Total = " << total << '.';
        } else {
            total -= t;
            cout << "Lose " << t << ".  Total = " << total << '.';
        }
        if (k)
            cout << '\n';
    }
}
