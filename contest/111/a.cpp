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
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) { pref[i + 1] = pref[i] + a[i]; }
	int left = 0, right = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int sa = (pref[i]) % 3;
			int sb = (pref[j] - pref[i]) % 3;
			int sc = (pref[n] - pref[j]) % 3;
			if (sa == sb && sc == sa) {
				left = i;
				right = j;
				break;
			}
			if (sa != sb && sa != sc && sb != sc) {
				left = i;
				right = j;
				break;
			}
		}
		if (left != 0 && right != 0) { break; }
	}
	cout << left << " " << right << endl;
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
