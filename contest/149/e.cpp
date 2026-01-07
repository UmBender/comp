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

const int MOD = 998244353;
const int MAX_M = 3005;
vector<int> adj[MAX_M];

void prep() {
	for (int i = 1; i < MAX_M; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				int v1 = i + j;
				if (v1 < MAX_M) { adj[i].push_back(v1); }

				int d2 = i / j;
				if (d2 != j) {
					int v2 = i + d2;
					if (v2 < MAX_M) adj[i].push_back(v2);
				}
			}
		}
		sort(adj[i].begin(), adj[i].end());
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	prep();
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	if (a[0] != 0 && a[0] != 1) {
		cout << 0 << endl;
		return;
	}

	vector<int> dp(m + 1, 0);

	dp[1] = 1;

	for (int i = 0; i < n - 1; ++i) {
		vector<int> ndp(m + 1, 0);
		bool possi = false;

		for (int j = 1; j <= m; j++) {
			if (dp[j] == 0) { continue; }

			for (int v : adj[j]) {
				if (v > m) { break; }

				if (a[i + 1] == 0 || a[i + 1] == v) {
					ndp[v] = (ndp[v] + dp[j]) % MOD;
					possi = true;
				}
			}
		}
		dp = ndp;
		if (!possi) { break; }
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) { ans = (ans + dp[i]) % MOD; }
	cout << ans << endl;
}
