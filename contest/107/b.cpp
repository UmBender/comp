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
	vector<vector<int>> grid(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '#') {
				grid[i][j] = 1;
			} else {
				grid[i][j] = 0;
			}
		}
	}
	bool okay = true;
	auto check = [&](int y, int x) -> bool {
		int counter = 0;
		vector<pair<int, int>> deltas = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (auto [i, j] : deltas) {
			int yy = i + y;
			int xx = j + x;
			bool status = (yy >= 0 && yy < h) && (xx >= 0 && xx < w);
			if (status) { counter += grid[yy][xx]; }
		}
		return counter == 2 || counter == 4;
	};
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == 1 && !check(i, j)) {
				okay = false;
				break;
			}
		}
	}
	cout << (okay ? "Yes" : "No") << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
