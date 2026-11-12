#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

string s;
constexpr int N = 7;
int acessed[N + 2][N + 2];
int acc = 0;

void dfs(int x, int y, int t) {
    if (x < 1 || x > 7) return;
    if (y < 1 || y > 7) return;

    if (x == 1 && y == 7) {
        if (t == 48) { acc++; }
        return;
    }

    if (t >= 48) return;

    if (acessed[y][x - 1] == 1 && acessed[y][x + 1] == 1 && acessed[y - 1][x] == 0 &&
        acessed[y + 1][x] == 0) {
        return;
    }

    if (acessed[y][x - 1] == 0 && acessed[y][x + 1] == 0 && acessed[y - 1][x] == 1 &&
        acessed[y + 1][x] == 1) {
        return;
    }

    if (s[t] == '?' || s[t] == 'R') {
        int dx = 1, dy = 0;
        if (!acessed[y + dy][x + dx]) {
            acessed[y + dy][x + dx] = 1;
            dfs(x + dx, y + dy, t + 1);
            acessed[y + dy][x + dx] = 0;
        }
    }
    if (s[t] == '?' || s[t] == 'L') {
        int dx = -1, dy = 0;
        if (!acessed[y + dy][x + dx]) {
            acessed[y + dy][x + dx] = 1;
            dfs(x + dx, y + dy, t + 1);
            acessed[y + dy][x + dx] = 0;
        }
    }
    if (s[t] == '?' || s[t] == 'U') {
        int dx = 0, dy = -1;
        if (!acessed[y + dy][x + dx]) {
            acessed[y + dy][x + dx] = 1;
            dfs(x + dx, y + dy, t + 1);
            acessed[y + dy][x + dx] = 0;
        }
    }
    if (s[t] == '?' || s[t] == 'D') {
        int dx = 0, dy = 1;
        if (!acessed[y + dy][x + dx]) {
            acessed[y + dy][x + dx] = 1;
            dfs(x + dx, y + dy, t + 1);
            acessed[y + dy][x + dx] = 0;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < N + 2; i++) {
        acessed[i][0] = 1;
        acessed[i][N + 1] = 1;
        acessed[0][i] = 1;
        acessed[N + 1][i] = 1;
    }
    cin >> s;
    acessed[1][1] = 1;
    dfs(1, 1, 0);
    cout << acc << endl;
    return 0;
}
