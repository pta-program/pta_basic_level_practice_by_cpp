#include <bits/stdc++.h>
using namespace std;
// 算法原理：按尝试顺序比较密码，首次匹配即成功，否则在次数耗尽后锁定账户。
// 关键步骤：读到 # 时立即结束，不把它当作一次密码尝试。
int main() {
    string pass, s;
    int n;
    cin >> pass >> n;
    while (n--) {
        cin >> s;
        if (s == "#")
            return 0;
        if (s == pass) {
            cout << "Welcome in";
            return 0;
        }
        cout << "Wrong password: " << s << '\n';
    }
    cout << "Account locked";
}
