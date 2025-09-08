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
	int k, x;
	cin >> k >> x;
	int total = 1LL << (k + 1);
	int a = x, b = total - x;
	vector<int> result;
	while (a != total / 2) {
		if (a * 2 > total) {
			result.push_back(1);
			a -= b;
			b *= 2;

		} else {
			result.push_back(0);
			b -= a;
			a *= 2;
		}
	}
	int op = result.size();
	reverse(result.begin(), result.end());
	cout << op << endl;
	for (int i = 0; i < op; i++) {
		cout << result[i] + 1 << " \n"[i == op - 1];
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
