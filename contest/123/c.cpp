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
	solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int mmin = MAX_INT;

	auto num_to_vec = [&n](int actual) -> vector<int> {
		vector<int> base;
		for (int i = 0; i < n; i++) { base.push_back((actual >> i) & 0b1); }
		return base;
	};

	auto calc = [&](vector<int> colors) -> int {
		int counter = 0;
		for (int i = 0; i < n; i++) {
			for (auto next : adj[i]) {
				if (colors[next] == colors[i]) { counter++; }
			}
		}
		return counter / 2;
	};

	for (int i = 0; i < (1LL << n); i++) {
		vector<int> actives = num_to_vec(i);
		mmin = min(calc(actives), mmin);
	}
	cout << mmin << endl;
}
