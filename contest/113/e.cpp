// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <queue>
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
	int n, k, x;
	cin >> n >> k >> x;
	map<double, int> a;
	for (int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		a[ai]++;
	}

	int hk = k;

	while (hk) {
		auto [key, value] = *a.rbegin();
		int remove = min(value, hk);
		hk -= remove;
		a[key] -= remove;
		a[key / 2.0] += 2LL * remove;
		if (a[key] == 0) { a.erase(key); }
	}
	int counter = 0;
	for (auto b = a.rbegin(); b != a.rend(); b++) {
		if (b->second + counter >= x) {
			cout << fixed << setprecision(9) << b->first << endl;
			return;
		}
		counter += b->second;
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
