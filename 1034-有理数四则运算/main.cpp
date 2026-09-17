#include <bits/stdc++.h>
using namespace std;
// 算法原理：使用分子分母表示有理数，每次运算后用最大公约数约分并格式化。
// 关键步骤：除法遇到分子为零时输出 Inf，并统一处理负号和带分数。
using ll = long long;
struct F {
    ll n, d;
};
ll gcd2(ll a, ll b) { return b ? gcd2(b, a % b) : llabs(a); }
F norm(F x) {
    if (x.d < 0)
        x.n = -x.n, x.d = -x.d;
    ll g = gcd2(x.n, x.d);
    return {x.n / g, x.d / g};
}
void out(F x) {
    x = norm(x);
    if (x.n == 0) {
        cout << 0;
        return;
    }
    bool neg = x.n < 0;
    if (neg)
        cout << '(';
    if (llabs(x.n) >= x.d)
        cout << x.n / x.d;
    else if (neg)
        cout << '-';
    if (llabs(x.n) >= x.d && llabs(x.n) % x.d)
        cout << ' ';
    if (llabs(x.n) % x.d)
        cout << llabs(x.n) % x.d << '/' << x.d;
    if (neg)
        cout << ')';
}
int main() {
    string sa, sb;
    cin >> sa >> sb;
    auto read = [](const string &s) {
        size_t slash = s.find('/');
        return F{stoll(s.substr(0, slash)), stoll(s.substr(slash + 1))};
    };
    F a = read(sa), b = read(sb);
    a = norm(a);
    b = norm(b);
    F x{a.n * b.d + b.n * a.d, a.d * b.d}, y{a.n * b.d - b.n * a.d, a.d * b.d},
        z{a.n * b.n, a.d * b.d}, q{a.n * b.d, a.d * b.n};
    out(a);
    cout << " + ";
    out(b);
    cout << " = ";
    out(x);
    cout << '\n';
    out(a);
    cout << " - ";
    out(b);
    cout << " = ";
    out(y);
    cout << '\n';
    out(a);
    cout << " * ";
    out(b);
    cout << " = ";
    out(z);
    cout << '\n';
    out(a);
    cout << " / ";
    out(b);
    cout << " = ";
    if (b.n == 0)
        cout << "Inf";
    else
        out(q);
}
