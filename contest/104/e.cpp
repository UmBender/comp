// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <execution>
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

struct DSU {
	vector<int> parent;
	vector<int> sizes;
	vector<int> counter;
	int size;
	DSU(int size) : parent(size), sizes(size, 1), counter(size, 0), size(size) {
		iota(parent.begin(), parent.end(), 0LL);
	}

	int get_parent(int node) {
		if (parent[node] == node) { return node; }
		int real_parent = get_parent(parent[node]);
		parent[node] = real_parent;
		return real_parent;
	}
	void join(int first, int second) {
		first = get_parent(first);
		second = get_parent(second);
		if (first == second) { return; }
		if (sizes[first] < sizes[second]) { swap(first, second); }
		sizes[first] += sizes[second];
		parent[second] = first;
		counter[first] += counter[second];
	}
	bool is_same(int first, int second) {
		first = get_parent(first);
		second = get_parent(second);
		return first == second;
	}
	int get_counter(int node) {
		node = get_parent(node);
		return counter[node];
	}
	void update_counter(int node, int delta) {
		node = get_parent(node);
		counter[node] += delta;
	}
};
void solution() {
	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	vector<int> color(n);
	for (int qq = 0; qq < q; qq++) {
		int type;
		cin >> type;
		switch (type) {
		case 1: {
			int u, v;
			cin >> u >> v;
			u--, v--;
			dsu.join(u, v);
		} break;
		case 2: {
			int v;
			cin >> v;
			v--;
			int delta;
			if (color[v] == 0) {
				delta = 1;
				color[v] = 1;
			} else {
				delta = -1;
				color[v] = 0;
			}
			dsu.update_counter(v, delta);
		} break;
		case 3: {
			int v;
			cin >> v;
			v--;
			int quant = dsu.get_counter(v);
			if (quant > 0) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		} break;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
