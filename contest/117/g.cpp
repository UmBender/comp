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

mt19937 rng(random_device{}());
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
int bsu(vector<int> &arr, int upper) {
	int left = 0;
	int right = arr.size() - 1;
	int mmin = MAX_INT;
	while (left <= right) {
		int m = (left + right) / 2;
		if (arr[m] >= upper) {
			mmin = m;
			right = m - 1;
		} else {
			left = m + 1;
		}
	}
	if (mmin == MAX_INT) { mmin = -1; }
	return mmin;
}

int bsl(vector<int> &arr, int lower) {
	int left = 0;
	int right = arr.size() - 1;
	int mmax = -1;
	while (left <= right) {
		int m = (left + right) / 2;
		if (arr[m] <= lower) {
			mmax = m;
			left = m + 1;
		} else {
			right = m - 1;
		}
	}
	return mmax;
}

void solution() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	map<int, int> keyvalue;
	int actual = 0;
	map<int,int> inv;
	for (int i = 0; i < a.size(); i++) {
		if (!keyvalue.count(a[i])) {
			keyvalue[a[i]] = actual;
			inv[actual] = a[i];
			actual++;
		}
	}
	vector<vector<int>> count(actual);
	for (auto &i : a) { i = keyvalue[i]; }
	for (int i = 0; i < n; i++) { count[a[i]].push_back(i); }

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		set<int> poss;
		for (int i = 0; i < 40 && poss.size() < 2; i++) {
			int random = (rng() % (r - l + 1)) + l;
			int actual = a[random];
			if (count[actual].size() <= (r + 1 - (l + 1) + 1) / 3) { continue; }
			auto &ref = count[actual];
			int cnt = upper_bound(ref.begin(), ref.end(), r) -
			          lower_bound(ref.begin(), ref.end(), l);
			if (cnt > (r + 1 - (l + 1) + 1) / 3) { poss.insert(inv[actual]); }
		}

		if (poss.empty()) {
			cout << -1;
		} else {
			for (auto i : poss) { cout << i << " "; }
		}
		cout << endl;
	}
}
