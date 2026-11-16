#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w, k; cin >> h >> w >> k;
    vector<string> grid(h);
    for (auto &gi : grid) cin >> gi;
    auto calc = [&](vector<string> &ac) -> vector<set<pair<int, int>>> {
        vector<vector<int>> used(h, vector<int>(w));
        auto dfs = [&](auto &&self, int y, int x, set<pair<int, int>>& group, char color) -> void {
            vector<pair<int, int>> ops = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto [dy, dx] : ops) {
                if (0 <= dy + y && dy + y < h && 0 <= dx + x && dx + x < w &&
                    !used[dy + y][dx + x] && ac[dy + y][dx + x] == color) {
                    group.insert({dy + y, dx + x});
                    used[dy + y][dx + x] = 1;
                    self(self, dy + y, dx + x, group, color);
                }
            }
        };
        vector<set<pair<int, int>>> ans;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] != '.' && !used[i][j]) {
                    set<pair<int, int>> nodes = {{i, j}};
                    used[i][j] = 1;
                    dfs(dfs, i, j, nodes, grid[i][j]);
                    ans.push_back(nodes);
                }
            }
        }
        return ans;
    };

	auto filter = [&](vector<set<pair<int, int>>> &temp) -> vector<set<pair<int,int>>> {
		vector<set<pair<int, int>>> ans;
		for (auto ti: temp) {
			if (ti.size() >= k) {
				ans.push_back(ti);
			}
		}
		return ans;
	};

	auto transform =[&](vector<string> oldGrid, vector<set<pair<int,int>>> &temp) -> vector<string> {
		vector<string> newGrid = oldGrid;
		for (auto& si: temp) {
			for (auto [y, x]: si) {
				newGrid[y][x] = '.';
			}
		}
		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < w; j ++) {
				if (newGrid[i][j] != '.') {
					int down = i + 1;
					while (down < h) {
						if (newGrid[down][j] == '.') {
							swap(newGrid[down][j], newGrid[down - 1][j]);
							down++;
						} else {
							break;
						}
					}
				}
			}
		}
		return newGrid;
	};


	for (int i = 0; i < 1000; i++) {
		auto nodes = calc(grid);
		nodes = filter(nodes);
		if (nodes.empty()) {
			cout << i << endl;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cout << grid[i][j];
				}
				cout << endl;
			}
			return 0;
		}
		grid = transform(grid, nodes);
	}

    return 0;
}
