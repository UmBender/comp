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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	int actual_value = a[k - 1];
	set<int> elements;
	for (int i = 0; i < n; i++) {
		if (!elements.count(a[i]) && a[i] >= actual_value) {
			elements.insert(a[i]);
		}
	}
	int actual_moment = 1;
	auto iter = elements.begin();
	bool okay = true;
	iter++;
	while (iter != elements.end()) {
		int diff = *iter - actual_value;
		if (actual_moment + diff > actual_value + 1) {
			okay = false;
			break;
		}
		actual_moment += diff;
		actual_value = *iter;
		iter++;
	}
	if (okay) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
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
