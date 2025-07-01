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

struct BIT {
	int n;
	vector<int> bit;
	BIT(int n) : n(n + 1), bit(n + 1) {}

	void add(int idx, int val) {
		for (++idx; idx < n; idx += idx & -idx) bit[idx] += val;
	}

	void range_add(int l, int r, int val) {
		add(l, val);
		add(r + 1, -val);
	}

	int point_query(int idx) {
		int ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
		return ret;
	}
};

void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }

	int actual_pref = n;
	vector<int> pref(n + 2);
	vector<int> other_pref(n + 2);
	vector<int> counter_numbers(n + 1);
	for (int i = 0; i < n; i++) { counter_numbers[a[i]]++; }
	for (int i = n; i >= 0; i--) { pref[i] = counter_numbers[i] + pref[i + 1]; }
	for (int i = 1; i <= n; i++) {
		if (counter_numbers[i - 1] == 0) {
			other_pref[i] = other_pref[i - 1];
			break;
		}
		other_pref[i] = counter_numbers[i - 1] - 1 + other_pref[i - 1];
	}

	for (int i = 0; i <= n; i++) {
		if (counter_numbers[i] == 0) {
			actual_pref = i;
			break;
		}
	}
	BIT bit(n + 1);
	for (int i = 0; i < counter_numbers.size() && i <= actual_pref; i++) {
		int minimal = counter_numbers[i];
		int maximal = counter_numbers[i] + pref[i + 1] + other_pref[i + 1];
		bit.range_add(minimal, maximal, 1);
	}
	vector<int> solutions(n + 1);
	for (int i = 0; i <= n; i++) { solutions[i] = min(bit.point_query(i), n-(i-1)); }
	for (int i = 0; i <= n; i++) { cout << solutions[i] << " \n"[i == n]; }
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
