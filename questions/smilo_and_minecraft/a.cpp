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
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> arr(n);
	for (auto &i : arr) { cin >> i; }
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'g') { grid[i][j] = 1; }
		}
	}
	vector<vector<int>> pref(n, vector<int>(m + 1));

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] = pref[i][j - 1] + grid[i][j - 1];
		}
	}

	int minimal = MAX_INT;
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j]) { counter++; }
		}
	}

	auto prefix_sum = [&](int x, int y) {
		int acc = 0;
		int inf_y = max(y - k + 1, 0LL);
		int sup_y = min(y + k - 1, (int)pref.size() - 1);

		int inf_x = max(x - k + 1, 0LL);
		int sup_x = min(x + k - 1, m - 1) + 1;
		for (int i = inf_y; i <= sup_y; i++) {
			acc += pref[i][sup_x] - pref[i][inf_x];
		}
		minimal = min(minimal, acc);
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '.') { prefix_sum(j, i); }
		}
	}

	cout << counter - minimal << endl;
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
