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
	vector<int> a(n);
	for (int &i : a) { cin >> i; }
	int acmin = MAX_INT;
	vector<int> mmin(n);
	for (int i = 0; i < n; i++) {
		mmin[i] = min(acmin, a[i]);
		acmin = min(acmin, a[i]);
	}
	vector<int> prefmin(n + 1);
	for (int i = 0; i < n; i++) { prefmin[i + 1] = prefmin[i] + mmin[i]; }

	if (n == 2) {
		if (a[0] > a[1]) {
			cout << a[0] + a[1] << endl;
		} else {
			cout << a[0] + a[0] << endl;
		}
		return;
	}
	if (a[0] >= a[1]) {
		cout << a[0] + a[1] << endl;
		return;
	}
	cout << 2 * a[0] << endl;
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
