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

int next_power(int value) {
	if (value == 0) { return 1; }
	int x = 1;
	while (x <= value) { x *= 2; }
	return x;
}
void solution() {
	int l, r;
	cin >> l >> r;
	int n = r - l + 1;
	vector<int> p(n, -1);
	vector<int> counter(33);

	for (int i = n - 1; i >= 0; i--) {
		if (p[i] == -1) {
			int pp = next_power(i) - 1;
			int opose = pp ^ i;
			p[i] = opose;
			p[opose] = i;
		} else {
			continue;
		}
	}

	int actual = 0;
	for (int i = 0; i < n; i++) { actual += i | p[i]; }
	cout << actual << endl;
	for (int i = 0; i < n; i++) { cout << p[i] << " "; }
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;

	while (t--) {
		solution();
		//
	}

	return 0;
}
