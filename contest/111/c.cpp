// clang-format off
#include <atcoder/modint>
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
using mint = atcoder::modint;
// clang-format on

void solution() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &i : a) { cin >> i; }
	for (auto &i : b) { cin >> i; }
	vector<int> as = a, bs = b;
	for (int i = 0; i < n; i++) {
		if (as[i] < bs[i]) { swap(as[i], bs[i]); }
	}
	// for (int i = 0; i < n; i++) { cout << as[i] << " \n"[i == n - 1]; }
	// for (int i = 0; i < n; i++) { cout << bs[i] << " \n"[i == n - 1]; }
	mint holder = 1;
	for (int i = 0; i < n - 1; i++) {
		if (as[i] > as[i + 1]) {
			holder = 0;
			break;
		}
		if (bs[i] > bs[i + 1]) {
			holder = 0;
			break;
		}
	}
	assert(holder.val() != 0);
	vector<mint> counter(n);
	// as[i] >= bs[i]
	// for (int i = 0; i < n; i++) { cout << as[i] << " \n"[i == n - 1]; }
	// for (int i = 0; i < n; i++) { cout << bs[i] << " \n"[i == n - 1]; }
	counter[0] = 2;
	for (int i = 1; i < n; i++) {
		if (as[i - 1] <= bs[i]) {
			counter[i] = 2;
		} else {
			counter[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) { holder *= counter[i]; }
	cout << holder.val() << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
