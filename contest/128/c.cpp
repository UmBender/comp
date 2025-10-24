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
#define makeconst(value) []() { return (value); }
using ll = long long;
using ld = long double;
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
	int t;
	cin >> t;
	while (t--) 
		solution();
	// clang-format on

	return 0;
}

void solution() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	ssort(a);
	vector<int> counter(n + 1);
	for (int i : a) { counter[i]++; }
	vector<int> pref(n + 1);
	for (int i = 1; i <= n; i++) { pref[i] = pref[i - 1] + counter[i]; }
	int mmax = 1;
	auto second = [&](int val) -> int {
		if (val + 1 > n) { return 0; }
		//dbg(min(2 * val - 1, n), val);
		return pref[min(2 * val - 1, n)] - pref[val];
	};
	auto third = [&](int val) -> int {
		if (val * 2 + 1 > n) { return 0; }
		//dbg(min(3 * val - 1, n), val * 2);
		return pref[min(3 * val - 1, n)] - pref[val * 2];
	};

	auto fourth = [&](int val) -> int {
		int left = 3 * val;
		int right = 4 * val - 1;
		if (left + 1 > n) { return 0; }
		//dbg(left, right);
		return pref[min(right, n)] - pref[left];
	};

	auto build = [&](int val) -> int {
		int sum = pref[val - 1];
		//dbg(val - 1);
		sum += second(val);
		sum += third(val);
		sum += fourth(val);
		return sum;
	};
	for (int i = 2; i <= n; i++) {
		int builded = build(i);
		//dbg(builded);
		if (builded <= k) { mmax = max(i, mmax); }
	}

	cout << mmax << endl;
}
