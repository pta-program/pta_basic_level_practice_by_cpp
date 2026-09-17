#include <bits/stdc++.h>
using namespace std;
// 算法原理：分别按购买人次和单价乘人次比较销量冠军与销售额冠军。
// 关键步骤：销售额使用 long long 计算，避免乘法溢出。
struct S {
    string id;
    long long price, num;
};
int main() {
    int n;
    cin >> n;
    vector<S> a(n);
    for (auto &x : a)
        cin >> x.id >> x.price >> x.num;
    auto p = max_element(a.begin(), a.end(), [](S &x, S &y) { return x.num < y.num; });
    auto q = max_element(a.begin(), a.end(),
                         [](S &x, S &y) { return x.price * x.num < y.price * y.num; });
    cout << p->id << ' ' << p->num << '\n' << q->id << ' ' << q->price * q->num;
}
