// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
#define makeconst(value) []( return (value);)
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (auto &i : grid) { cin >> i; }
	function<char(char)> invert = [&](char opt) -> char {
		switch (opt) {
		case '.':
			return '.';
		case '#':
			return '#';
		case 'S':
			return 'S';
		case 'G':
			return 'G';
		case 'o':
			return 'x';
		case 'x':
			return 'o';
		default:
			return '?';
		}
	};
	vector<vector<set<pair<int, int>>>> adj(h * 2,
	                                        vector<set<pair<int, int>>>(w));
	for (int i = 0; i < h; i++) {
		string temp;
		for (int j = 0; j < w; j++) { temp.push_back(invert(grid[i][j])); }
		grid.push_back(temp);
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

			function<pair<int, int>(int, int)> next_node =
			    [&](int line, int column) -> pair<int, int> {
				switch (grid[line][column]) {
				case '#':
					return {-1, -1};
				case 'x':
					return {-1, -1};
				case '?':
					return {(line + h) % (2 * h), column};
				default:
					return {line, column};
				}
			};
			for (auto &[x, y] : dirs) {
				if (y + i >= 0 && y + i < h && x + j >= 0 && x + j < w) {
					auto [ny, nx] = next_node(y + i, x + j);
					if (ny != -1 && nx != -1) { adj[i][j].insert({ny, nx}); }
					auto [nny, nnx] = next_node(y + i + h, x + j);
					if (nny != -1 && nnx != -1) {
						adj[i + h][j].insert({nny, nnx});
					}
				}
			}
		}
	}
	int ybegin, xbegin;
	int yend, xend;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == 'S') {
				ybegin = i;
				xbegin = j;
			}
			if (grid[i][j] == 'G') {
				yend = i;
				xend = j;
			}
		}
	}
	vector<vector<int>> shortest(2 * h, vector<int>(w, MAX_INT));
	priority_queue<pair<int, pair<int, int>>,
	               std::vector<pair<int, pair<int, int>>>,
	               std::greater<pair<int, pair<int, int>>>>
	    q;
	q.push({0, make_pair(ybegin, xbegin)});

	while (!q.empty()) {
		auto [cost, node] = q.top();
		q.pop();
		auto [y, x] = node;
		if (shortest[y][x] <= cost) { continue; }
		shortest[y][x] = cost;
		for (auto &[next_y, next_x] : adj[y][x]) {
			q.push({cost + 1, {next_y, next_x}});
		}
	}
	if (shortest[yend][xend] == MAX_INT &&
	    shortest[yend + h][xend] == MAX_INT) {
		cout << -1 << endl;
	} else {
		cout << min(shortest[yend][xend], shortest[yend + h][xend]) << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
