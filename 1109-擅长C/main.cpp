#include <bits/stdc++.h>
using namespace std;
// 算法原理：保存 26 个字母点阵，提取句子中的大写单词后逐行拼接点阵。
// 关键步骤：非大写字符作为单词分隔符，单词之间输出一个空行。
int main() {
    vector<vector<string>> f(26, vector<string>(7));
    for (int c = 0; c < 26; ++c)
        for (int r = 0; r < 7; ++r)
            cin >> f[c][r];
    string line;
    getline(cin, line);
    getline(cin, line);
    vector<string> w;
    for (int i = 0; i < (int)line.size();) {
        while (i < (int)line.size() && !isupper((unsigned char)line[i]))
            ++i;
        int j = i;
        while (j < (int)line.size() && isupper((unsigned char)line[j]))
            ++j;
        if (j > i)
            w.push_back(line.substr(i, j - i));
        i = j;
    }
    for (int q = 0; q < (int)w.size(); ++q) {
        if (q)
            cout << '\n';
        for (int r = 0; r < 7; ++r) {
            for (int i = 0; i < (int)w[q].size(); ++i) {
                if (i)
                    cout << ' ';
                cout << f[w[q][i] - 'A'][r];
            }
            cout << '\n';
        }
    }
}
