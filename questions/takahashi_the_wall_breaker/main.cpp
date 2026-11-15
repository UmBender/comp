#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (string &si : grid) cin >> si;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;

    vvi dists(h, vi(w, 1e9));
    deque<tuple<int, int, int>> nodes;
    nodes.emplace_back(b, a, 0);
    dists[a][b] = 0;
    vector<pii> ops1 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pii> ops2 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-2, 0}, {2, 0}, {0, -2}, {0, 2}};

    while (!nodes.empty()) {
        auto [x, y, cost] = nodes.front();
        nodes.pop_front();
        if (cost > dists[y][x]) continue;
        for (auto [dx, dy] : ops1) {
            if (x + dx >= 0 && x + dx < w && y + dy >= 0 && y + dy < h) {
                if (grid[y + dy][x + dx] == '.' && cost < dists[y + dy][x + dx]) {
                    nodes.emplace_front(x + dx, y + dy, cost);
                    dists[y + dy][x + dx] = cost;
                }
            }
        }
        for (auto [dx, dy] : ops2) {
            if (x + dx >= 0 && x + dx < w && y + dy >= 0 && y + dy < h) {
                if (cost + 1 < dists[y + dy][x + dx]) {
                    nodes.emplace_back(x + dx, y + dy, cost + 1);
                    dists[y + dy][x + dx] = cost + 1;
                }
            }
        }
    }
    cout << dists[c][d] << endl;

    return 0;
}
