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
#define makeconst(value) []( return (value);)
using ll = long long;
using ld = long double;
#define int ll
using i64 = long long; using u64 = unsigned long long; using f32 = float; using f64 = double; using f128  = long double;
using mint = atcoder::modint;
// clang-format on

void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<mint> counter[2] = {vector<mint>(n), vector<mint>(n)};
	vector<int> mmax(n);
	vector<mint> okay(n);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			for (int k = j; k < n; j++) {
				int counter = 0;

			}
			counter[0][i] += 2;
			counter[1][i] += 2;
		}

		counter[0][i] += 1;
		counter[1][i] += 1;
	}
	mint acc = 0;
	for (int i = 0; i < n; i++) {
		acc += counter[0][i];
		acc += counter[1][i];
	}
	cout << acc.val() << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	atcoder::modint::set_mod(1E9 + 7);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
