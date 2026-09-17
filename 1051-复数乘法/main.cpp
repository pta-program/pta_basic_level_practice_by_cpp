#include <bits/stdc++.h>
using namespace std;
// 算法原理：将极坐标复数转换为直角坐标，使用复数乘法公式计算并格式化。
// 关键步骤：绝对值小于 0.005 的结果按零处理，消除 -0.00。
int main() {
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double a = r1 * cos(p1) * r2 * cos(p2) - r1 * sin(p1) * r2 * sin(p2),
           b = r1 * cos(p1) * r2 * sin(p2) + r2 * cos(p2) * r1 * sin(p1);
    if (fabs(a) < 0.005)
        a = 0;
    if (fabs(b) < 0.005)
        b = 0;
    cout << fixed << setprecision(2) << a << (b >= 0 ? "+" : "") << b << "i";
}
