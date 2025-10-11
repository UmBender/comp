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
	while(t--)
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	vector<vector<int>> adj(n);
	vector<vector<int>> rev_adj(n);
	for (int mm = 0; mm < m; mm++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		rev_adj[b].push_back(a);
	}

	set<int> actual_nodes;
	set<int> next_nodes;
	actual_nodes.insert(0);
	for (int i = 0; i < 2 * k; i++) {
		for (int actual : actual_nodes) {
			for (auto next : adj[actual]) {
				if (!next_nodes.count(next)) { next_nodes.insert(next); }
			}
		}
		swap(actual_nodes, next_nodes);
		next_nodes.clear();
	}
	vector<int> ending;
	for (int node : actual_nodes) { ending.push_back(node); }
	vector<vector<int>> color(2 * k + 1, vector<int>(n));
	for (int i = 0; i < ending.size(); i++) {
		if (s[ending[i]] == 'B') {
			color[0][ending[i]] = 1;
		} else {
			color[0][ending[i]] = -1;
		}
	}
	for (int i = 0; i < 2 * k; i++) {
		if (i % 2 == 0) {
			for (int node = 0; node < n; node++) {
				if (color[i][node] == 0) { continue; }
				if (color[i][node] == 1) {
					for (auto next : rev_adj[node]) { color[i + 1][next] = 1; }
				} else {
					for (auto next : rev_adj[node]) {
						if (!color[i + 1][next]) { color[i + 1][next] = -1; }
					}
				}
			}
		} else {
			for (int node = 0; node < n; node++) {
				if (color[i][node] == 0) { continue; }
				if (color[i][node] == -1) {
					for (auto next : rev_adj[node]) { color[i + 1][next] = -1; }
				} else {
					for (auto next : rev_adj[node]) {
						if (!color[i + 1][next]) { color[i + 1][next] = 1; }
					}
				}
			}
		}
	}
	if (color[2 * k][0] == 1) {
		cout << "Bob" << endl;
	} else {
		cout << "Alice" << endl;
	}
}
