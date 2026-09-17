#include <bits/stdc++.h>
using namespace std;
// 算法原理：忽略越界互评分，去除合法分数中的最高最低后与老师分取平均。
// 关键步骤：排序后累加 begin+1 到 end-1 的分数。
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int teacher;
        cin >> teacher;
        vector<int> a;
        for (int j = 1; j < n; ++j) {
            int x;
            cin >> x;
            if (x >= 0 && x <= m)
                a.push_back(x);
        }
        sort(a.begin(), a.end());
        double sum = accumulate(a.begin() + 1, a.end() - 1, 0.0);
        cout << lround((sum / (a.size() - 2) + teacher) / 2) << '\n';
    }
}
