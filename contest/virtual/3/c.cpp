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
using ll = long long;
using ld = long double;
#define int ll
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int n;
	cin >> n;
	vector<int> upper(n);
	vector<int> bottom(n);
	for (auto &i : upper) { cin >> i; }
	for (auto &i : bottom) { cin >> i; }

	set<int> up_cells;
	set<int> down_cells;
	for (int i = 0; i < n; i++) {
		if (upper[i] > bottom[i]) {
			up_cells.insert(i);
		} else {
			down_cells.insert(i);
		}
	}
	int actual_sum = 0;
	for (auto i : up_cells) { actual_sum += upper[i]; }
	for (auto i : down_cells) { actual_sum += bottom[i]; }
	vector<vector<int>> grid(2);
	grid[0] = upper;
	grid[1] = bottom;
	int twice = -1;
	int side = -1;
	for (int i = 0; i < n; i++) {
		if (twice == -1) {
			if (up_cells.count(i)) {
				twice = i;
				side = 1;
			} else {
				twice = i;
				side = 0;
			}

		} else {
			if (up_cells.count(i)) {
				if (grid[side][twice] < grid[1][i]) {
					side = 1;
					twice = i;
				}
			} else {
				if (grid[side][twice] < grid[0][i]) {
					side = 0;
					twice = i;
				}
			}
		}
	}

	cout << actual_sum + grid[side][twice] << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
