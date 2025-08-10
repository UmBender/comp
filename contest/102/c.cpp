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
	int n, k;
	cin >> n >> k;
	vector<int> s(n), t(n);
	for (auto &i : s) { cin >> i; }
	for (auto &i : t) { cin >> i; }
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	for (auto &i : s) {
		int mult = (i / k);
		i -= mult * k;
	}
	for (auto &i : t) {
		int mult = (i / k);
		i -= mult * k;
	}
	map<int, int> smap, tmap;
	for (auto i : s) {
		smap[i]++;
		smap[abs(i - k)]++;
	}
	for (auto i : t) {
		tmap[i]++;
		tmap[abs(i - k)]++;
	}
	for (auto &[key, value] : smap) {
		if (value != tmap[key]) {
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
