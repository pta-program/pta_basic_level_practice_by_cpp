#include <bits/stdc++.h>
using namespace std;
// 算法原理：按 A 末尾 9 的个数构造数字和 n，再 DFS 枚举满足位数和的前缀。
// 关键步骤：固定末尾 9 后只枚举前缀数字，并限制前缀末位不为 9。
bool prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
int ds(long long x) {
    int s = 0;
    while (x)
        s += x % 10, x /= 10;
    return s;
}
int main() {
    int q;
    cin >> q;
    for (int cs = 1; cs <= q; ++cs) {
        int k, m;
        cin >> k >> m;
        vector<pair<int, long long>> ans;
        for (int nine = 1; nine <= k; ++nine) {
            int n = m + 1 - 9 * nine;
            if (n <= 0)
                continue;
            int g = gcd(m, n);
            if (!(g > 2 && prime(g)))
                continue;
            int len = k - nine, target = m - 9 * nine;
            if (target < 1 || target > 9 * len)
                continue;
            string pref(len, '0');
            function<void(int, int)> dfs = [&](int pos, int sum) {
                if (pos == len) {
                    if (sum != target || pref.back() == '9')
                        return;
                    string s = pref + string(nine, '9');
                    ans.push_back({n, stoll(s)});
                    return;
                }
                int lo = pos == 0 ? 1 : 0, hi = 9;
                if (pos == len - 1)
                    hi = 8;
                for (int d = lo; d <= hi && sum + d <= target; ++d) {
                    int left = len - pos - 1;
                    if (target - sum - d < 0 || target - sum - d > 9 * left)
                        continue;
                    pref[pos] = '0' + d;
                    dfs(pos + 1, sum + d);
                }
            };
            dfs(0, 0);
        }
        sort(ans.begin(), ans.end());
        cout << "Case " << cs << '\n';
        if (ans.empty())
            cout << "No Solution\n";
        else
            for (auto &x : ans)
                cout << x.first << ' ' << x.second << '\n';
    }
}
