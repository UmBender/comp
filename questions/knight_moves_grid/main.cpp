#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
mt19937 rng(random_device{}());

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 1e9));
    vector<vector<bool>> acessed(n, vector<bool>(n));
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, 0)));
    vector<pair<int, int>> ops = {{2, -1}, {2, 1}, {-2, -1}, {-2, 1},
                                  {-1, 2}, {1, 2}, {-1, -2}, {1, -2}};
    grid[0][0] = 0;
    acessed[0][0] = true;
    while (!q.empty()) {
        auto [val, point] = q.front();
        auto [x, y] = point;
        q.pop();
        for (auto [dx, dy] : ops) {
            int nx = x + dx, ny = y + dy;
            if (nx <0 || nx >= n || ny < 0 || ny >= n) {
                continue;
            }
            if (!acessed[nx][ny]) {
                acessed[nx][ny] = true;
                grid[nx][ny] = val + 1;
                q.push(make_pair(val + 1, make_pair(nx, ny)));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}
