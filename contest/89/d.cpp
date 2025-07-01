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
	int n, k;
	cin >> n >> k;
	string aa;
	cin >> aa;
	vector<int> a(n);
	int one_counter = 0;
	for (int i = 0; i < n; i++) {
		if (aa[i] == '1') {
			a[i] = 1;
			one_counter++;
		} else {
			a[i] = 0;
		}
	}

	if (one_counter <= k) {
		cout << "Alice" << endl;
		return;
	}
	if (n % 2 == 0) {
		if (n / 2 >= k) {
			cout << "Bob" << endl;
			return;
		} else {
			cout << "Alice" << endl;
			return;
		}

	} else {
		if ((n + 1) / 2 <= k) {
			cout << "Alice" << endl;
			return;
		} else {
			cout << "Bob" << endl;

			return;
		}
	}
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
