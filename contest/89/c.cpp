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
using ll = long long;
using ld = long double;
#define int ll
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int mmax[n + 1], mmin[n + 1];
	fill(mmax, mmax + n + 1, 0);
	fill(mmin, mmin + n + 1, MAX_INT);
	for (int i = 1; i <= n; i++) { mmin[i] = min(mmin[i - 1], a[i - 1]); }
	for (int i = n - 1; i >= 0; i--) { mmax[i] = max(mmax[i + 1], a[i]); }
	string result;
	for (int i = 0; i < n; i++) {
		if (a[i] <= mmin[i] || a[i] >= mmax[i + 1]) {
			result += '1';
		} else {
			result += '0';
		}
	}
	cout << result << endl;
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
