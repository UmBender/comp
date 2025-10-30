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
#define makeconst(value) []() { return (value); }
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
#define ssort(x) ranges::sort(x)
#define mkunique(x) ranges::sort(x), x.erase(unique(x.begin(), x.end()), x.end()), x.shrink_to_fit()
//using mint = atcoder::modint;
// clang-format on

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}


void solution() {
	int n;
	cin >> n;
	string grid[n];
	for (int i = 0; i < n; i++) { cin >> grid[i]; }
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (grid[i][j - 1] == '#' && grid[i][j] == '#' &&
			    grid[i][j + 1] == '#') {
				cout << "NO" << endl;
				return;
			}
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i - 1][j] == '#' && grid[i][j] == '#' &&
			    grid[i + 1][j] == '#') {
				cout << "NO" << endl;
				return;
			}
		}
	}
	set<pair<int, int>> blacks;
	map<int, int> prin, secon;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '#') {
				blacks.insert({i, j});
				prin[i - j]++;
				secon[i + j]++;
			}
		}
	}
	int counter = blacks.size();
	if (counter == 0 || counter == 1) {
		cout << "YES" << endl;
		return;
	}
	for (int i = -n; i <= n; i++) {
		if (prin[i] + prin[i + 1] == counter) {
			cout << "YES" << endl;
			return;
		}
	}
	for (int i = 0; i <= 2 * n; i++) {
		if (secon[i] + secon[i + 1] == counter) {
			cout << "YES" << endl;
			return;
		}
	}
	if (counter == 4) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (grid[i][j] == '#' && grid[i + 1][j] == '#' &&
				    grid[i][j + 1] == '#' && grid[i + 1][j + 1] == '#') {
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
}
