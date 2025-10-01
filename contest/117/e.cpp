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
//
//                                if (right - left + 1 > r) {
//                                	if (pos.count(left)) {
//                                		iters.erase(a[left]);
//                                		pos.erase(left);
//                                	}
//                                	left++;
//                                	continue;
//                                } else {
//                                	if (iters.count(a[right])) {
//                                		pos.erase(iters[a[right]]);
//                                		pos.insert(right);
//                                		iters[a[right]] = right;
//                                	} else {
//                                		iters[a[right]] = right;
//                                		pos.insert(right);
//                                	}
//                                	if (iters.size() == k) {
//                                		int minimal = max(right - l,
//                                *pos.begin() +
//                                1);
//                                		counter += minimal - left;
//                                		dbg(minimal - left);
//                                	} else if (iters.size() > k) {
//                                		int last = *pos.begin();
//                                		iters.erase(a[last]);
//                                		pos.erase(last);
//                                		left = last + 1;
//                                		continue;
//                                	}
//                                	right++;
//                                }
//
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
	int n, k, l, r;
	cin >> n >> k >> l >> r;
	vector<int> a(n);
	int counter = 0;
	map<int, int> iters;
	set<int> pos;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int left = 0;
	int right = 0;
	while (right < n) {

		int interval_size = right - left + 1;
		if (interval_size <= r) {
			int actual = a[right];
			if (iters.count(actual)) { pos.erase(iters[actual]); }
			iters[actual] = right;
			pos.insert(right);
			if (iters.size() < k) {
				right++;
				continue;
			}
			if (iters.size() > k) {
				int last = *pos.begin();
				pos.erase(last);
				iters.erase(a[last]);
				left = last + 1;
				continue;
			}
			if (iters.size() == k) {
				if (right - left + 1 >= l) {
					int minimal = *pos.begin();
					int left_minimal = right - l + 1;
					int real = min(minimal, left_minimal);
					counter += real - left + 1;
					right++;

				} else {
					right++;
				}
			}
		} else {
			int value = a[left];
			if (iters[value] == left) {
				iters.erase(value);
				pos.erase(left);
			}
			left++;
			continue;
		}
	}
	cout << counter << endl;
}
