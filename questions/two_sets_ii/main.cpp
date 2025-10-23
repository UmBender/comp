// clang-format off
#include <atcoder/modint>
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
#define makeconst(value) []() { return (value); }
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
#define ssort(x) ranges::sort(x)
#define mkunique(x) ranges::sort(x), x.erase(unique(x.begin(), x.end()), x.end()), x.shrink_to_fit()
using mint = atcoder::modint;
// clang-format on

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	atcoder::modint::set_mod(1e9 + 7);
	// clang-format off
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	int all_sum = ((n + 1) * n) / 2;
	if (all_sum % 2) {
		cout << 0 << endl;
		return;
	}
	vector<mint> counter(all_sum + 1);
	counter[0] = 1;
	for (int i = n; i >= 1; i--) {
		for (int c = all_sum; c - i >= 0; c--) { counter[c] += counter[c - i]; }
	}
	cout << (counter[all_sum / 2] / 2).val() << endl;
}
