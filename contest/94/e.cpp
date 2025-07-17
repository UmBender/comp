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
	vector<int> p(n), s(n);
	for (auto &i : p) { cin >> i; }
	for (auto &i : s) { cin >> i; }
	for (int i = 1; i < n; i++) {
		int result = gcd(p[i - 1], p[i]);
		if (result != p[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	for (int i = n - 1; i > 0; i--) {
		int result = gcd(s[i], s[i - 1]);
		if (result != s[i - 1]) {
			cout << "NO" << endl;
			return;
		}
	}
	int upper = p[0];
	for (int i = 0; i < n; i++) {
		upper = gcd(upper, p[i]);
		if (upper != p[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	int lower = s[n-1];
	for (int i = n - 1; i >= 0; i--) {
		lower = gcd(lower, s[i]);
		if (lower != s[i]) {
			cout << "NO" << endl;
			return;
		}
	}

	int full_gcd = s[0];
	if (full_gcd != p.back() || full_gcd != lower || full_gcd != upper) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 1; i < n; i++) {
		int actual_gcd = gcd(p[i - 1], s[i]);
		if (actual_gcd != full_gcd) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
