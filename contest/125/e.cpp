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

int counter[200100];
int sol[200100];
void solution() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		counter[i + 1] = 0;
	}
	for (int i = 0; i < n; i++) {
		counter[a[i]]++;
	}
	int not_used = 0;

	for (int i = 1; i <= n; i++) {
		if (!counter[i]) {
			not_used = i;
			break;
		}
	}

	if (not_used == 0) {
		for (int i = 0; i < k; i++) { cout << a[i] << " "; }
		cout << endl;
		return;
	}
	sol[0] = not_used;

	for (int i = 1; i <= n; i++) {
		if (sol[0] != i && a[n - 1] != i) { sol[1] = i; break;}
	}
	int pos = 2;
	for (int i = 1; i <= n; i++) {
		if (sol[0] != i && sol[1] != i) {
			sol[pos] = i;
			pos++;
		}
	}
	for (int i = 0; i < k; i++) { cout << sol[i] << " "; }
	cout << endl;
}
