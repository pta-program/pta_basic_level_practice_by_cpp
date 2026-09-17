#include <bits/stdc++.h>
using namespace std;
// 算法原理：建立准考证号到名次的映射，再按名次是否为 1、素数分类输出奖项。
// 关键步骤：查询后记录不再重复领奖，保持题目要求的奖项语义。
bool prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    map<string, int> rank;
    for (int i = 1; i <= n; ++i) {
        string x;
        cin >> x;
        rank[x] = i;
    }
    int k;
    cin >> k;
    set<string> checked;
    while (k--) {
        string x;
        cin >> x;
        if (!rank.count(x))
            cout << x << ": Are you kidding?";
        else if (checked.count(x))
            cout << x << ": Checked";
        else if (rank[x] == 1)
            cout << x << ": Mystery Award";
        else if (prime(rank[x]))
            cout << x << ": Minion";
        else
            cout << x << ": Chocolate";
        checked.insert(x);
        if (k)
            cout << '\n';
    }
}
