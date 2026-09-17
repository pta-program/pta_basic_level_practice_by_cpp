#include <bits/stdc++.h>
using namespace std;
// 算法原理：维护已出现数字集合，判断新数是否为其中两数之差且未重复出现。
// 关键步骤：按轮次、玩家编号顺序处理，出局玩家后续数字不再读取参与判断。
int main() {
    int x, y, n, m;
    cin >> x >> y >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a)
        for (int &z : r)
            cin >> z;
    set<int> seen = {x, y};
    vector<bool> alive(n, true);
    for (int r = 0; r < m; ++r) {
        vector<int> out;
        for (int i = 0; i < n; ++i)
            if (alive[i]) {
                int z = a[i][r];
                bool possible = false;
                for (int u : seen)
                    for (int v : seen)
                        if (u != v && abs(u - v) == z)
                            possible = true;
                if (seen.count(z) || !possible)
                    alive[i] = false, out.push_back(i + 1);
                else
                    seen.insert(z);
            }
        for (int i : out)
            cout << "Round #" << r + 1 << ": " << i << " is out.\n";
    }
    vector<int> w;
    for (int i = 0; i < n; ++i)
        if (alive[i])
            w.push_back(i + 1);
    if (w.empty())
        cout << "No winner.";
    else {
        cout << "Winner(s):";
        for (int i : w)
            cout << ' ' << i;
    }
}
