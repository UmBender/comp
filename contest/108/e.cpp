// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <ostream>
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
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<int> counter(n + 1);
	for (int i = 0; i < n; i++) { counter[a[i]]++; }
	int first_missing = n;
	int first_dup = n;
	for (int i = 0; i < n; i++) {
		if (counter[i] == 0 && first_missing == n) { first_missing = i; }
		if (counter[i] > 1 && first_dup == n) { first_dup = i; }
	}
	if (first_missing < first_dup) {
		int new_k = k - 1;
		vector<int> new_a = a;
		for (int i = 0; i < n; i++) {
			if (new_a[i] > first_missing) { new_a[i] = first_missing; }
		}
		for (int i = 0; i <= n; i++) { counter[i] = 0; }
		for (int i = 0; i < n; i++) { counter[new_a[i]]++; }
		bool okay = true;
		for (int i = 0; i < n; i++) {
			if (counter[i] != 1) { okay = false; }
		}
		if (okay) {
			int sum = 0;
			for (int i = 0; i < n; i++) { sum += new_a[i]; }
			cout << sum << endl;
			return;
		}
		vector<int> new_new_a = new_a;
		for (int i = 0; i < n; i++) {
			if (new_new_a[i] == first_missing) {
				new_new_a[i] = first_missing + 1;
			}
		}
		int sum = 0;
		if (new_k % 2 == 0) {
			for (int i = 0; i < n; i++) { sum += new_a[i]; }
		} else {
			for (int i = 0; i < n; i++) { sum += new_new_a[i]; }
		}
		cout << sum << endl;
		return;

	} else if (first_dup < first_missing) {
		int new_k = k - 1;
		vector<int> new_a = a;

		for (int i = 0; i < n; i++) {
			if (new_a[i] < first_dup) { continue; }
			if (new_a[i] < first_missing) {
				if (counter[new_a[i]] > 1) { new_a[i] = first_missing; }
				continue;
			}
			if (new_a[i] > first_missing) { new_a[i] = first_missing; }
		}
		for (int i = 0; i <= n; i++) { counter[i] = 0; }
		for (int i = 0; i < n; i++) { counter[new_a[i]]++; }

		bool okay = true;
		for (int i = 0; i < n; i++) {
			if (counter[i] != 1) { okay = false; }
		}
		if (okay) {
			int sum = 0;
			for (int i = 0; i < n; i++) { sum += new_a[i]; }
			cout << sum << endl;
			return;
		}

		if (new_k == 0) {
			int sum = 0;
			for (int i = 0; i < n; i++) { sum += new_a[i]; }
			cout << sum << endl;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (new_a[i] > first_dup) { new_a[i] = first_dup; }
		}
		new_k--;
		if (new_k % 2 == 0) {
			int sum = 0;
			for (int i = 0; i < n; i++) { sum += new_a[i]; }
			cout << sum << endl;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (new_a[i] == first_dup) { new_a[i] = first_dup + 1; }
		}
		int sum = 0;
		for (int i = 0; i < n; i++) { sum += new_a[i]; }
		cout << sum << endl;
		return;

	} else {
		// first_missing == first_dup => first_dup == 2 == first_missing
		int sum = 0;
		for (int i = 0; i < n; i++) { sum += a[i]; }
		cout << sum << endl;
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
