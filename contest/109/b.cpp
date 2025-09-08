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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	sort(a.rbegin(), a.rend());
	vector<int> ar = a;
	int acc = 0;
	if (m <= n) {
		int counter = 0;
		int multiplier = m;
		while (counter < m) {
			acc += a[counter] * multiplier;
			counter++;
			multiplier--;
		}

		cout << acc << endl;
		return;
	}
	int delta = m - n;
	int counter = 0;
	int multiplier = n;
	while(counter < n) {
		acc += ar[counter] * (multiplier + delta);
		counter++;
		multiplier--;
	}
	cout << acc << endl;
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
