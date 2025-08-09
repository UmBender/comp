// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <iomanip>
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
	string s;
	cin >> s;
	int n;
	n = s.size();
	ld factor = 0.0f;
	for (int i = 0; i < n; i++) {
		if (s[i] != 't') { continue; }
		int counter = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == 't') { counter++; }
			if (j - i + 1 >= 3 && s[j] == 't') {
				factor = max(factor, static_cast<ld>(counter - 2) /
				                         static_cast<ld>(j - i + 1 - 2));
			}
		}
	}
	cout << setprecision(32) << factor << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
