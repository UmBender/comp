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
	vector<pair<int, int>> rec(3);
	for (ll k = 0; k < 3; k++) { cin >> rec[k].first >> rec[k].second; }
	if (rec[0].first == rec[1].first && rec[1].first == rec[2].first &&
	    rec[0].first == rec[0].second + rec[1].second + rec[2].second) {
		cout << "YES" << endl;
		return;
	}

	if (rec[0].first == rec[1].first + rec[2].first &&
	    rec[1].second == rec[2].second &&
	    rec[1].second + rec[0].second == rec[0].first) {
		cout << "YES" << endl;
		return;
	}
	for (auto &i : rec) { swap(i.first, i.second); }

	if (rec[0].first == rec[1].first && rec[1].first == rec[2].first &&
	    rec[0].first == rec[0].second + rec[1].second + rec[2].second) {
		cout << "YES" << endl;
		return;
	}

	if (rec[0].first == rec[1].first + rec[2].first &&
	    rec[1].second == rec[2].second &&
	    rec[1].second + rec[0].second == rec[0].first) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
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
