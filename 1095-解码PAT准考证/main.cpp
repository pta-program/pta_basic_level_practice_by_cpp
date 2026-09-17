#include <bits/stdc++.h>
using namespace std;
// 算法原理：根据查询类型筛选准考证号的级别、考场或日期字段并排序统计。
// 关键步骤：类型 3 先按日期过滤，再对考场编号计数并排序。
struct S {
    string id;
    int score;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<S> a(n);
    for (auto &x : a)
        cin >> x.id >> x.score;
    for (int q = 1; q <= m; ++q) {
        int type;
        string key;
        cin >> type >> key;
        cout << "Case " << q << ": " << type << ' ' << key << '\n';
        if (type == 1) {
            vector<S> v;
            for (auto &x : a)
                if (x.id[0] == key[0])
                    v.push_back(x);
            sort(v.begin(), v.end(),
                 [](S &x, S &y) { return x.score != y.score ? x.score > y.score : x.id < y.id; });
            if (v.empty())
                cout << "NA\n";
            else
                for (auto &x : v)
                    cout << x.id << ' ' << x.score << '\n';
        } else if (type == 2) {
            int cnt = 0, sum = 0;
            for (auto &x : a)
                if (x.id.substr(1, 3) == key)
                    ++cnt, sum += x.score;
            if (!cnt)
                cout << "NA\n";
            else
                cout << cnt << ' ' << sum << '\n';
        } else {
            map<string, pair<int, int>> c;
            for (auto &x : a)
                if (x.id.substr(4, 6) == key)
                    ++c[x.id.substr(1, 3)].first, c[x.id.substr(1, 3)].second = 0;
            for (auto &x : a)
                if (x.id.substr(4, 6) == key)
                    c[x.id.substr(1, 3)].second++;
            vector<pair<string, int>> v;
            for (auto &[id, z] : c)
                v.push_back({id, z.first});
            sort(v.begin(), v.end(), [](auto &x, auto &y) {
                return x.second != y.second ? x.second > y.second : x.first < y.first;
            });
            if (v.empty())
                cout << "NA\n";
            else
                for (auto &x : v)
                    cout << x.first << ' ' << x.second << '\n';
        }
    }
}
