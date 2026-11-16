#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

constexpr int MAXH = 22;
constexpr int MAXW = 22;
constexpr int BOX = 0;
constexpr int ROB = 1;
constexpr int INF = 1e9;

int total[MAXH][MAXW][MAXH][MAXW][2];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) cin >> grid[i];
    pii start, target, box;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') { start = {i, j}; }
            if (grid[i][j] == 'T') { target = {i, j}; }
            if (grid[i][j] == 'B') { box = {i, j}; }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < h; k++) {
                for (int l = 0; l < w; l++) {
                    total[i][j][k][l][BOX] = INF;
                    total[i][j][k][l][ROB] = INF;
                }
            }
        }
    }
    total[start.first][start.second][box.first][box.second][BOX] = 0;
    total[start.first][start.second][box.first][box.second][ROB] = 0;
    using State = array<int, 6>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, start.first, start.second, box.first, box.second});
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto ins = [&](int y, int x) {
        return y >= 0 && y < h && x >= 0 && x < w && grid[y][x] != '#';
    };
    while (!pq.empty()) {
        auto [boxCost, robCost, ry, rx, by, bx] = pq.top();
        pq.pop();
        int oldRobCost = total[ry][rx][by][bx][ROB];
        int oldBoxCost = total[ry][rx][by][bx][BOX];
        if (make_pair(boxCost, robCost) > make_pair(oldBoxCost, oldRobCost)) { continue; }

        if (by == target.first && bx == target.second) {
            cout << boxCost << " " << robCost << endl;
            return 0;
        }
        for (auto [dy, dx] : dir) {
            int nry = ry + dy;
            int nrx = rx + dx;
            if (!ins(nry, nrx)) { continue; }
            if (nry == by && nrx == bx) {
                int nby = by + dy;
                int nbx = bx + dx;
                if (!ins(nby, nbx)) continue;
                int nBoxCost = boxCost + 1;
                int nRobCost = robCost + 1;
                int &newOldRobCost = total[nry][nrx][nby][nbx][ROB];
                int &newOldBoxCost = total[nry][nrx][nby][nbx][BOX];

                if (make_pair(nBoxCost, nRobCost) < make_pair(newOldBoxCost, newOldRobCost)) {
                    newOldBoxCost = nBoxCost;
                    newOldRobCost = nRobCost;
                    pq.push({nBoxCost, nRobCost, nry, nrx, nby, nbx});
                }
            } else {
                int nBoxCost = boxCost;
                int nRobCost = robCost + 1;
                int &newOldRobCost = total[nry][nrx][by][bx][ROB];
                int &newOldBoxCost = total[nry][nrx][by][bx][BOX];

                if (make_pair(nBoxCost, nRobCost) < make_pair(newOldBoxCost, newOldRobCost)) {
                    newOldBoxCost = nBoxCost;
                    newOldRobCost = nRobCost;
                    pq.push({nBoxCost, nRobCost, nry, nrx, by, bx});
                }
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
