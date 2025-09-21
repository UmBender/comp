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
	int n, m;
	cin >> n >> m;
	vector<set<int>> sn(n);
	vector<int> sizes(n);
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		sizes[i] = l;
		for (int j = 0; j < l; j++) {
			int actual;
			cin >> actual;
			sn[i].insert(actual);
		}
	}

	vector<int> counter(m);
	for (int i = 0; i < n; i++) {
		for (auto val : sn[i]) { counter[val - 1]++; }
	}

	bool okay = true;
	for (int i = 0; i < m; i++) {
		if (!counter[i]) {
			okay = false;
			break;
		}
	}

	if (!okay) {
		cout << "NO" << endl;
		return;
	}

	int possibilities = 1;

	for (int i = 0; i < n; i++) {
		bool okay = true;
		for (int val : sn[i]) {
			if (counter[val - 1] - 1 < 1) {
				okay = false;
				break;
			}
		}
		if (okay) { possibilities++; }
		if (possibilities >= 3) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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
