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
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	map<int, int> side_counters;
	for (int i = 0; i < n; i++) { side_counters[a[i]]++; }
	int mmax_pem{0};
	int actual_pem{0};
	int actual_sides = 0;
	for (auto [len, count] : side_counters) {
		if (count >= 2) {
			int num = count - (count % 2);
			actual_pem += len * (num);
			actual_sides += num;
		}
		if (actual_sides >= 3) { mmax_pem = actual_pem; }
	}
	actual_pem = max(mmax_pem, actual_pem);
	vector<int> pairs;
	for (auto [len, count] : side_counters) {
		if (count % 2) { pairs.push_back(len); }
	}
	if (pairs.empty()) {
		cout << mmax_pem << endl;
		return;
	}

	for (int i = 0; i < static_cast<int>(pairs.size()) - 1; i++) {
		if (actual_pem + pairs[i] > pairs[i + 1] && actual_sides + 2 >= 3) {
			mmax_pem = max(mmax_pem, actual_pem + pairs[i] + pairs[i + 1]);
		}
	}
	for (int i = 0; i < static_cast<int>(pairs.size()); i++) {
		if (actual_pem > pairs[i] && actual_sides + 1 >= 3) {
			mmax_pem = max(mmax_pem, actual_pem + pairs[i]);
		}
	}
	cout << mmax_pem << endl;
}
