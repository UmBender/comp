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
	map<int, vector<int>> max_as_origin;
	int mmax = 0;
	for (int i = 1; i <= n; i++) {
		cout << format("? {} {} ", i, n);
		for (int j = 1; j <= n; j++) { cout << j << " \n"[j == n]; }
		cout.flush();
		int longest;
		cin >> longest;
		mmax = max(mmax, longest);
		max_as_origin[longest].push_back(i);
	}
	int begin = max_as_origin[mmax].front();
	vector<int> conections;
	conections.push_back(begin);
	for (int value = mmax - 1; value > 0; value--) {
		for (int node : max_as_origin[value]) {
			cout << format("? {} {} {} {}", conections.back(), 2,
			               conections.back(), node)
			     << endl;
			cout.flush();
			int response;
			cin >> response;
			if (response == 2) {
				conections.push_back(node);
				break;
			}
		}
	}
	cout << format("! {} ", mmax);
	for (int i = 0; i < mmax; i++) {
		cout << conections[i] << " \n"[i == mmax - 1];
	}
	cout.flush();
}

int32_t main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
