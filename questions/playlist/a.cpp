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
	int n;
	cin >> n;
	vector<int> x(n);
	for (auto &i : x) { cin >> i; }
	map<int, set<int>> positions;
	for (int i = 0; i < n; i++) { positions[x[i]].insert(i); }
	map<int, int> last;

	int mmax = 0;
	int actual = 0;
	for (int i = 0; i < n; i++) {
		if (last.count(x[i]) == 0) {
			last[x[i]] = i;
			mmax = max(mmax, i - actual + 1);
			continue;
		}
		if (last[x[i]] < actual) {
			last.erase(i);
			last[x[i]] = i;
			mmax = max(mmax, i - actual + 1);
			continue;
		}
		actual = last[x[i]] + 1;
		last[x[i]] = i;
		mmax = max(mmax, i - actual + 1);
	}
	cout << mmax << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
