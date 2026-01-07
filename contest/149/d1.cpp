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
    while (t--) { 
        solution();
	}
	// clang-format on

	return 0;
}

void solution() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> height(n + 1, -1);
	vector<int> width_acc(n + 1, 0);
	vector<int> childrens(n + 1, 0);

	queue<int> q;
	q.push(1);
	height[1] = 0;
	width_acc[0]++;

	int max_height = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (height[v] == -1) {
				height[v] = height[u] + 1;
				width_acc[height[v]]++;
				childrens[u]++;
				max_height = max(max_height, height[v]);
				q.push(v);
			}
		}
	}

	int mmax = 0;
	for (int i = 0; i <= max_height; i++) { mmax = max(mmax, width_acc[i]); }

	for (int i = 1; i <= n; i++) { mmax = max(mmax, childrens[i] + 1); }

	cout << mmax << endl;
}
