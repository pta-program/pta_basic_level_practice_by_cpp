#include <bits/stdc++.h>
using namespace std;
// 算法原理：累加每支队伍的个人成绩，再找总分最高的队伍。
// 关键步骤：使用 map 自动合并同一队伍的多条成绩记录。
int main() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; ++i) {
        string id;
        int score;
        cin >> id >> score;
        a[stoi(id.substr(0, id.find('-')))] += score;
    }
    auto p = max_element(a.begin(), a.end(), [](auto &x, auto &y) { return x.second < y.second; });
    cout << p->first << ' ' << p->second;
}
