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


void solution() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> elves(n);
	for(int i = 0; i < n; i++) {
		cin >> elves[i].first;
		elves[i].second = i + 1;
	}
	sort(elves.begin(), elves.end());
	if(m == 0) {
		int others = 0;
		for(int i = 0; i < n - 1; i++) {
			others += elves[i].first;
		}
		if(others < elves[n - 1].first) {
			cout << -1 << endl;
			return;
		}
		cout << n - 1 << endl;
		int boss = elves[n - 1].first;
		int k = 0;
		while(k < n - 1 && boss > elves[k].first) {
			boss -= elves[k].first;
			k++;
		}
		for(int i = 0; i < k; i++) {
			cout << elves[i].second << " " << elves[n - 1].second << endl;
		}
		for(int i = k; i < n - 2; i ++) {
			cout << elves[i].second << " " << elves[i + 1].second << endl;
		}
		cout << elves[n-1].second << ' ' << elves[n - 2].second << endl;
	} else {
		if(2 *m > n) {
			cout << -1 << endl;
		}else {
			cout << n - m << endl;

			int rem = n - 2 * m;
			for(int i = 0; i < rem; i++) {
				cout << elves[i].second << " " << elves[i + 1].second << endl;
			}

			int base = n - 2 * m;
			int surv = n - m;

			for(int i = 0; i < m; i++) {
				cout << elves[surv + i].second << " " << elves[base + i].second << endl;
			}
		}

	}
}
