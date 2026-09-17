#include <bits/stdc++.h>
using namespace std;
// 算法原理：按试机座位号建立索引，查询时直接取出准考证号和考试座位号。
// 关键步骤：试机座位号作为数组下标，实现常数时间查询。
struct S {
    string id;
    int seat;
};
int main() {
    int n;
    cin >> n;
    vector<S> a(1001);
    for (int i = 0, test, exam; i < n; ++i) {
        string id;
        cin >> id >> test >> exam;
        a[test].id = id;
        a[test].seat = exam;
    }
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << a[x].id << ' ' << a[x].seat << '\n';
    }
}
