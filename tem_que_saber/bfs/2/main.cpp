#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (string& gi: grid) {
		cin >> gi;
	}

	vii moves = {{0, - 1}, {0, 1}, {-1, 0}, {1, 0}};
	auto check = [&](int y, int x) -> bool {
		return (y >= 0 && y < h && x >= 0 && x < w);
	};

	auto remOcean = [&](auto &&self, int y, int x) {
		if (grid[y][x] == '#') return;
		grid[y][x] = '#';
		for (auto [dy, dx]: moves) {
			if (check(y + dy, x + dx)) {
				self(self, y + dy, x + dx);
			}
		}
	};
	for (int i = 0; i < h; i++) {
		remOcean(remOcean, i, 0);
		remOcean(remOcean, i, w - 1);
	}
	for (int j = 0; j < w; j++) {
		remOcean(remOcean, 0, j);
		remOcean(remOcean, h - 1, j);
	}

	int mmax = 0, cnt = 0, total = 0;
	auto dfs = [&](auto&& self, int y, int x, int& acc) {
		if (grid[y][x] == '#') return; 
		grid[y][x] = '#';
		acc++;
		for (auto [dy, dx]: moves) {
			if (check(y + dy, x + dx)) {
				self(self, y + dy, x + dx, acc);
			}
		}
	};
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == '#') continue;
			cnt++;
			int acc = 0;
			dfs(dfs, i, j, acc);
			total += acc;
			mmax = max(mmax, acc);
		}
	}
	cout << cnt << " " << total << " " << mmax << endl;
	return 0;
}

