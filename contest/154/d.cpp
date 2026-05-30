#include <bits/stdc++.h>

using namespace std;
using i32 = int;
using i64 = long long;
#define endl '\n'
#define int i64

signed main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    int black = 0;

    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') {
                black++;
            }
        }
    }

    if (black == 0 || black == h * w) {
        for (int i = 0; i < h; i++) {
            cout << string(w, '.') << endl;
        }
        return 0;
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> q;

    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') {
                bool white = false;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                        if (grid[ni][nj] == '.') {
                            white = true;
                            break;
                        }
                    }
                }
                if (white) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        string ans = "";
        for (int j = 0; j < w; j++) {
            if (dist[i][j] != -1 && dist[i][j] % 2 == 0) {
                ans += '#';
            } else {
                ans += '.';
            }
        }
        cout << ans << endl;
    }

    return 0;
}
