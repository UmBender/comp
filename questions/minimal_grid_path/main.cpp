#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solution();
signed main() { solution(); }
void solution() {
	int n;
	cin >> n;
	vector<string> g(n);
	for (auto &s : g) { cin >> s; }
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { mat[i][j] = g[i][j] - 'A'; }
	}
	vector<int> minimal(2 * n, 1e18);
	vector<pair<int, int>> next_nodes;
	vector<pair<int, int>> actual_nodes;
	vector<vector<bool>> acessed(n, vector<bool>(n));
	vector<vector<bool>> green(n, vector<bool>(n));
	actual_nodes.push_back({0, 0});
	auto op = [&](int row, int column) {
		if (acessed[row][column]) { return; }
		acessed[row][column] = true;
		if (mat[row][column] == minimal[row + column]) {
			next_nodes.push_back({row, column});
		} else if (mat[row][column] < minimal[row + column]) {
			next_nodes.clear();
			next_nodes.push_back({row, column});
			minimal[row + column] = mat[row][column];
		}
	};
	for (int i = 0; i < 2 * n; i++) {
		for (auto [r, c] : actual_nodes) {
			green[r][c] = true;
			if (r + 1 < n) { op(r + 1, c); }
			if (c + 1 < n) { op(r, c + 1); }
		}
		actual_nodes.clear();
		swap(actual_nodes, next_nodes);
	}
	vector<pair<int, int>> path;
	path.push_back({n - 1, n - 1});
	pair<int, int> beginn = make_pair(0ll, 0ll);
	while (beginn != path.back()) {
		auto [r, c] = path.back();
		if (r - 1 >= 0 && green[r - 1][c]) {
			path.push_back({r - 1, c});
			continue;
		}
		path.push_back({r, c - 1});
	}
	ranges::reverse(path);
	string s;
	for (int i = 0; i < path.size(); i++) {
		auto [row, col] = path[i];
		char c = mat[row][col] + 'A';
		s.push_back(c);
	}
	cout << s << endl;
}
