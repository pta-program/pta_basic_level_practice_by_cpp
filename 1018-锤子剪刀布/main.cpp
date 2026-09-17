#include <bits/stdc++.h>
using namespace std;
// 算法原理：用胜负规则统计双方战绩和各手势胜场，并按字母序处理并列。
// 关键步骤：甲胜场统计用于甲的最佳手势，乙胜场统计用于乙的最佳手势。
int main() {
    int n;
    cin >> n;
    map<char, int> ca{{'B', 0}, {'C', 0}, {'J', 0}}, cb = ca;
    int aw = 0, draw = 0;
    auto win = [](char a, char b) {
        return (a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C');
    };
    while (n--) {
        char a, b;
        cin >> a >> b;
        if (a == b)
            ++draw;
        else if (win(a, b))
            ++aw, ++ca[a];
        else
            ++cb[b];
    }
    int loss = 0;
    for (auto &[c, x] : cb)
        loss += x;
    cout << aw << ' ' << draw << ' ' << loss << '\n' << loss << ' ' << draw << ' ' << aw << '\n';
    cout << max_element(ca.begin(), ca.end(),
                        [](auto &a, auto &b) {
                            return a.second == b.second ? a.first > b.first : a.second < b.second;
                        })
                ->first
         << ' ' << max_element(cb.begin(), cb.end(), [](auto &a, auto &b) {
                       return a.second == b.second ? a.first > b.first : a.second < b.second;
                   })->first;
}
