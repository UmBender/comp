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
	vector<int> b(n);
	for (auto &i : a) { cin >> i; }
	for (auto &i : b) { cin >> i; }
	if (a.back() != b.back()) {
		cout << "NO" << endl;
		return;
	}
	int aacc = a.back();
	int bacc = b.back();
	for (int i = n - 2; i >= 0; i--) {
		if ((aacc | a[i]) != (bacc | b[i])) {
			cout << "NO" << endl;
			return;
		}
		aacc |= a[i];
		bacc |= b[i];
	}
	for (int i = n - 2; i >= 0; i--) {
		if (!((a[i] ^ a[i + 1]) == b[i] || (a[i] ^ b[i + 1]) == b[i] || a[i] == b[i])) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
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
