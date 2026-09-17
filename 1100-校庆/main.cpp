#include <bits/stdc++.h>
using namespace std;
// 算法原理：集合判断来宾是否为校友，并按身份证生日字段寻找最年长者。
// 关键步骤：有校友时只在校友中取最年长，否则在全部来宾中取最年长。
int main() {
    int n;
    cin >> n;
    set<string> a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a.insert(s);
    }
    int m;
    cin >> m;
    string oldestGuest, oldestAlumnus;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (oldestGuest.empty() || s.substr(6, 8) < oldestGuest.substr(6, 8))
            oldestGuest = s;
        if (a.count(s)) {
            ++cnt;
            if (oldestAlumnus.empty() || s.substr(6, 8) < oldestAlumnus.substr(6, 8))
                oldestAlumnus = s;
        }
    }
    cout << cnt << '\n' << (cnt ? oldestAlumnus : oldestGuest);
}
