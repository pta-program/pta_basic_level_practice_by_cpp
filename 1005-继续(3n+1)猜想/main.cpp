#include <bits/stdc++.h>
using namespace std;
// 算法原理：生成每个数的 Collatz 覆盖路径，再从候选集合中排除被其他路径覆盖的数。
// 关键步骤：只把路径中再次出现的候选数标记为已覆盖。
int main() {
    int k;
    cin >> k;
    vector<int> a(k);
    set<int> input, covered;
    for (int &x : a)
        cin >> x, input.insert(x);
    for (int x : a) {
        while (x != 1) {
            x = x % 2 ? 3 * x + 1 : x / 2;
            if (input.count(x))
                covered.insert(x);
        }
    }
    sort(a.rbegin(), a.rend());
    bool first = true;
    for (int x : a)
        if (!covered.count(x)) {
            if (!first)
                cout << ' ';
            cout << x;
            first = false;
        }
}
