#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
#define endl '\n'

signed main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(h, vector<int>(w, 0));


    auto isValid = [&](int i, int j) -> int {
        if (i < 0 || j < 0 || i >= h || j >= w) {
            return 0;
        }
        return 1;
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            g[i][j] += isValid(i, j + 1);
            g[i][j] += isValid(i, j - 1);
            g[i][j] += isValid(i - 1, j);
            g[i][j] += isValid(i + 1, j);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << g[i][j] << " \n"[j == w - 1];
        }
    }
}
