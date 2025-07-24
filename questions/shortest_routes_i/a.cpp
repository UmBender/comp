// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <queue>
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
using isize = long long;
using usize = unsigned long long;
//using mint = atcoder::modint;
// clang-format on

void solution() {
	isize n, m;
	cin >> n >> m;
	vector<isize> dist(n, MAX_INT);
	dist[0] = 0;
	vector<map<isize, isize>> adj(n);
	for (isize i = 0; i < m; i++) {
		isize a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		if (adj[a].count(b)) {
			adj[a][b] = min(adj[a][b], c);
		} else {
			adj[a][b] = c;
		}
		if (a == 0) { dist[b] = min(c, dist[b]); }
	}
	// value, node
	priority_queue<pair<int, int>, vector<pair<int, int>>,
	               greater<pair<int, int>>>
	    q;
	for (auto &[i, j] : adj[0]) { q.push({j, i}); }
	while (!q.empty()) {
		auto [actual_value, actual_node] = q.top();
		q.pop();
		if (actual_value > dist[actual_node]) { continue; }
		for (auto [next_node, cost] : adj[actual_node]) {

			if (cost + actual_value < dist[next_node]) {
				dist[next_node] = cost + actual_value;
				q.push({dist[next_node], next_node});
			}
		}
	}
	for (isize i = 0; i < n; i++) { cout << dist[i] << " \n"[i == n - 1]; }
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
