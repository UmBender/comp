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
	solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector<int> pref[2];
	pref[0] = vector<int>(n + 1);
	pref[1] = vector<int>(n + 1);
	vector<int> t(n);
	for (int i = 0; i < n; i++) { t[i] = s[i] == 'b'; }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			pref[j][i + 1] = pref[j][i] + (t[i] == j);
		}
	}

	int counter = 0;
	auto q = [&](int pos) -> int {
		auto big_a =
		    lower_bound(pref[0].begin() + pos, pref[0].end(), a + pref[0][pos]);
		if (big_a == pref[0].end()) { return 0; }
		auto small_b =
		    lower_bound(pref[1].begin() + pos, pref[1].end(), b + pref[1][pos]);
		int left = big_a - pref[0].begin(), right = small_b - pref[1].begin();
		if (left > right) { return 0; }
		return right - left;
	};
	for (int i = 0; i < n; i++) { counter += q(i); }
	cout << counter << endl;
}
