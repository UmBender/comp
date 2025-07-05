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
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if ((~1LL & a) > (~1LL & b)) {
		cout << -1 << endl;
		return;
	}
	if (a > b) {
		cout << y << endl;
		return;
	}
	if (a == b) {
		cout << 0 << endl;
		return;
	}
	int move = x;
	int one = min(x, y);
	int acc = 0;
	int actual = a;
	while (actual < b) {
		if (actual % 2 == 1) {
			actual++;
			acc += move;
		} else {
			actual++;
			acc += one;
		}
	}
	cout << acc << endl;
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
