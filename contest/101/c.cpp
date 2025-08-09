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

auto bs(vector<int> &arr, int target) -> int {
	int l = 0, r = arr.size() - 1;
	int minimal = MAX_INT;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] >= target) {
			minimal = min(minimal, m);
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (minimal == MAX_INT) { return -1; }
	return minimal;
}
void solution() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<int> b(q);
	for (auto &i : b) { cin >> i; }
	sort(a.begin(), a.end());
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) { pref[i + 1] = pref[i] + a[i]; }
	for (int qq = 0; qq < q; qq++) {
		int target = b[qq];
		int minimal = bs(a, target);
		if (minimal == -1) {
			cout << -1 << endl;
			continue;
		}
		int first = pref[minimal];
		int second = (n - minimal - 1) * (target - 1);
		int result = first + second + target;
		cout << result << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
