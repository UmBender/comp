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
	int n, q;
	cin >> n >> q;
	vector<int> a(n), b(n);
	for (auto &i : a) { cin >> i; }
	for (auto &i : b) { cin >> i; }
	int sum = 0;
	for (int i = 0; i < n; i++) { sum += min(a[i], b[i]); }
	for (int qq = 0; qq < q; qq++) {
		char c;
		int x, v;
		cin >> c >> x >> v;
		x--;
		sum -= min(a[x], b[x]);
		if (c == 'A') {
			a[x] = v;
		} else {
			b[x] = v;
		}
		sum += min(a[x], b[x]);
		cout << sum << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
