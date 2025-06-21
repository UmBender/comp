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

const bool WHITE = false;
const bool BLACK = true;
void solution() {
	ll n, q;
	cin >> n >> q;
	vector<bool> a(n, WHITE);
	ll counter = 0;
	vector<ll> query(q);
	for (auto &k : query) {
		cin >> k;
		k--;
	}
	auto black_neighbours = [&](ll pos) -> ll {
		int countern = 0;
		if (pos > 0) { countern += a[pos - 1]; }
		if (pos < n - 1) { countern += a[pos + 1]; }
		return countern;
	};
	for (auto k : query) {
		if (a[k] == WHITE) {
			ll countern = black_neighbours(k);
			if (countern == 0) {
				counter++;
			} else if (countern == 2) {
				counter--;
			}
			a[k] = BLACK;
		} else if (a[k] == BLACK) {
			ll countern = black_neighbours(k);
			if (countern == 0) {
				counter--;
			} else if (countern == 2) {
				counter++;
			}

			a[k] = WHITE;
		}
		cout << counter << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
