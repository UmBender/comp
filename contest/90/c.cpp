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
	int q;
	cin >> q;
	vector<pair<int, int>> counter;
	int actual = 0;
	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int c, x;
			cin >> c >> x;
			counter.push_back({c, x});
		} else {
			int k;
			cin >> k;
			int sum = 0;
			while (counter[actual].first < k) {
				sum += counter[actual].first * counter[actual].second;
				k -= counter[actual].first;
				actual++;
			}
			sum += counter[actual].second * k;
			counter[actual].first -= k;
			cout << sum << endl;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
