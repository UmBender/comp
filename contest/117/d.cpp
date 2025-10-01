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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> ss(n);
	int counter0 = 0, counter1 = 0;
	vector<int> zeros;
	vector<int> ones;
	for (int i = 0; i < n; i++) {
		ss[i] = s[i] == 'a';
		if (ss[i]) {
			counter1++;
			ones.push_back(i);
		} else {
			counter0++;
			zeros.push_back(i);
		}
	}

	if (counter0 <= 1 || counter1 <= 1) {
		cout << 0 << endl;
		return;
	}
	int left = 0;
	int right = n - 1;
	int zerol = 0;
	int zeror = n - 1;
	int cost = 0;
	while (zerol <= zeror) {
		if (ss[zerol]) {
			zerol++;
			continue;
		}
		if (ss[zeror]) {
			zeror--;
			continue;
		}
		int left_cost = zerol - left;
		int right_cost = right - zeror;
		if (left_cost < right_cost) {
			cost += left_cost;
			left++;
			zerol++;
		} else {
			cost += right_cost;
			right--;
			zeror--;
		}
	}
	int mmin_cost = cost;
	left = 0;
	right = n - 1;
	int oner = n - 1;
	int onel = 0;
	cost = 0;
	while (onel <= oner) {
		if (ss[onel] == 0) {
			onel++;
			continue;
		}
		if (ss[oner] == 0) {
			oner--;
			continue;
		}
		int left_cost = onel - left;
		int right_cost = right - oner;
		if (left_cost <= right_cost) {
			cost += left_cost;
			left++;
			onel++;
		} else {
			cost += right_cost;
			right--;
			oner--;
		}
	}
	cout << min(mmin_cost, cost) << endl;
}
