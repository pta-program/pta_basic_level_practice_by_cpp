#include <bits/stdc++.h>
using namespace std;
// 算法原理：先验证插入排序特征，否则按二路归并的轮次模拟并寻找当前状态。
// 关键步骤：输出识别到的下一轮排序结果，而不是当前输入状态。
void print(vector<int> &a) {
    for (int i = 0; i < (int)a.size(); ++i)
        cout << (i ? " " : "") << a[i];
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    int pos = 0;
    while (pos + 1 < n && b[pos] <= b[pos + 1])
        ++pos;
    bool ins = true;
    for (int i = pos + 1; i < n; ++i)
        if (a[i] != b[i])
            ins = false;
    if (ins) {
        sort(b.begin(), b.begin() + min(pos + 2, n));
        cout << "Insertion Sort\n";
        print(b);
        return 0;
    }
    vector<int> x = a;
    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += width * 2)
            sort(x.begin() + i, x.begin() + min(i + width * 2, n));
        if (x == b) {
            width *= 2;
            for (int i = 0; i < n; i += width * 2)
                sort(x.begin() + i, x.begin() + min(i + width * 2, n));
            cout << "Merge Sort\n";
            print(x);
            return 0;
        }
    }
}
