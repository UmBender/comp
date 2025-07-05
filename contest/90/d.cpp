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
using ll = long long;
using ld = long double;
#define int ll
//using mint = atcoder::modint;
// clang-format on

void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }

	int first = abs(a[0]);
	bool all_equal = true;
	for (int i = 0; i < n; i++) {
		if (abs(a[i]) != first) { all_equal = false; }
	}
	if (all_equal) {
		int pos = 0, neg = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {
				neg++;
			} else {
				pos++;
			}
		}
		if (pos == 0 || neg == 0) {
			cout << "Yes" << endl;
			return;
		}
		if (abs(pos - neg) <= 1) {
			cout << "Yes" << endl;
			return;
		}
		cout << "No" << endl;
		return;
	}

	sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });
	int pos = 0;
	int neg = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			neg++;
		} else {
			pos++;
		}
	}
	if (!(pos == 0 || neg == 0 || abs(pos - neg) <= 1)) {
		cout << "No" << endl;
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		if (a[i + 1] * a[i + 1] != a[i + 2] * a[i] ) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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
