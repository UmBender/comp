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
#define makeconst(value) []() { return (value); } using ll = long long;
using ld = long double;
using ll = long long;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
#define ssort(x) ranges::sort(x)
#define mkunique(x) ranges::sort(x), x.erase(unique(x.begin(), x.end()), x.end()), x.shrink_to_fit()
//using mint = atcoder::modint;
// clang-format on

void solution();
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	// clang-format off
	solution();
	// clang-format on

	return 0;
}

int pref[(int)2e5 + 100];
void solution() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int counter[n + 1];
	fill(counter, counter + n + 1, 0LL);
	for (int i = 0; i < n; i++) { counter[a[i]]++; }
	pref[0] = 0;
	pref[1] = 0;
	pref[2] = 1;
	for (int i = 3; i <= n; i++) { pref[i] = (i - 1) + pref[i - 1]; }
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += pref[counter[i]];
	}

	int all = 0;
	for (int i = 1; i <= n; i++) {
		int partial = (sum - pref[counter[i]]) * counter[i];
		all += partial;
	}
	cout << all << endl;
}
