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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	if (n == 1) {
		cout << a.front() + k << endl;
		return;
	}
	if (k % 2 == 1) {
		for (auto &i : a) {
			if (i % 2 == 1) { i += k; }
		}
	} else if (k == 2) {
		for (auto &i : a) {
			int imp = 3;

			int times = (i % imp);
			if (times != imp) { i += (times)*k; }
		}

	} else {
		for (auto &i : a) {
			int imp = k - 1;
			int times = (imp) - (i % imp);
			if (times != imp) { i += (times)*k; }
		}
	}
	for (int i = 0; i < n; i++) { cout << a[i] << " \n"[i == n - 1]; }
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
