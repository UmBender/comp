// clang-format off
//#include <atcoder/all>
#include <bit>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", "; __dbg(rest...);
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

int bit_length(int val) {
	int counter = 0;
	while (val) {
		counter++;
		val /= 2;
	}
	return counter;
}
void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<pair<int, int>> lr(q);
	for (auto &[l, r] : lr) {
		cin >> l >> r;
		l--, r--;
	}
	vector<int> ops(n);
	for (int i = 0; i < n; i++) {
		int actual = a[i];
		while (actual >= 2) {
			actual /= 2;
			ops[i]++;
			if (actual >= 2) { actual++; }
		}
	}
	vector<int> pref(n + 1);
	vector<int> pref2(n + 1);
	for (int i = 0; i < n; i++) {
		int val = __builtin_popcountll(a[i]);
		int val_inc = __builtin_popcountll(a[i] + 1);
		if (val == 2 && (val_inc == 2 || val_inc == 1)) {
			pref2[i + 1] = pref2[i] + 1;
		} else {
			pref2[i + 1] = pref2[i];
		}
	}

	for (int i = 0; i < n; i++) { pref[i + 1] = pref[i] + ops[i]; }
	for (auto [l, r] : lr) {
		cout << pref[r + 1] - pref[l] + (pref2[r + 1] - pref2[l]) / 2 << endl;
	}
}
