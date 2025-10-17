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
	int a, b;
	cin >> a >> b;
	vector<int> a_bits(64), b_bits(64);
	for (int i = 0; i < 64; i++) {
		a_bits[i] = ((a >> i) & 0b1);
		b_bits[i] = ((b >> i) & 0b1);
	}
	int a_max = -1;
	int b_max = -1;
	for (int i = 0; i < 64; i++) {
		if (a_bits[i]) { a_max = max(a_max, i); }
		if (b_bits[i]) { b_max = max(b_max, i); }
	}

	if (a_max == -1 && b_max != -1) {
		cout << -1 << endl;
		return;
	}

	if (b_max == -1 && a_max != -1) {
		cout << 1 << endl;
		cout << a << endl;
		return;
	}
	if (a_max < b_max) {
		cout << -1 << endl;
		return;
	}
	vector<int> nums;
	for (int i = 0; i <= a_max; i++) {
		if (a_bits[i] != b_bits[i]) { nums.push_back(1ll << i); }
	}
	cout << nums.size() << endl;
	if (nums.size() == 0) { return; }
	for (int i = 0; i < nums.size(); i++) { cout << nums[i] << " "; }
	cout << endl;
}
