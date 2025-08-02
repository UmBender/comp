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

int n, m;
map<int, int> a, b;
void solution() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int actual;
		cin >> actual;
		a[actual]++;
	}
	for (int i = 0; i < m; i++) {
		int actual;
		cin >> actual;
		b[actual]++;
	}
	for (auto &[i, j] : b) {
		if (a.count(i)) {
			a[i] = max(0LL, a[i] - j);
			if (a[i] <= 0) { a.erase(i); }
		}
	}
	vector<int> result;
	for (auto &[i, j] : a) {
		for (int k = 0; k < j; k++) { result.push_back(i); }
	}
	int size = static_cast<int>(result.size());
	for (int i = 0; i < size; i++) {
		cout << result[i] << " \n"[i == size - 1];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
