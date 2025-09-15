// clang-format off
//#include <atcoder/all>
#include <algorithm>
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
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for (int i = 0; i < n; i++) { cin >> c[i]; }
	sort(c.begin(), c.end());
	int max_value = (3* max(c.back(), 2LL) )/2;
	vector<int> dp(max_value + 1);
	for (int i = 0; i < n; i++) { dp[c[i]]++; }
	vector<int> pref(max_value + 1);
	for (int i = 1; i <= max_value; i++) { pref[i] = pref[i - 1] + dp[i]; }
	int mmax = -(n * x);
	for (int i = 2; i <= max_value; i++) {
		int sum = 0;
		int replaced = 0;
		for (int j = 1; j * i <= max_value; j++) {
			int left = i * (j - 1) + 1;
			int right = i * j;
			sum += (pref[right] - pref[left - 1]) * j;

			replaced += min(pref[right] - pref[left - 1], dp[j]);
		}
		mmax = max(mmax, sum - (n - replaced) * x);
	}
	cout << mmax << endl;
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
