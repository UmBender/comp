// clang-format off
#include "atcoder/segtree.hpp"
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

using SegMin = atcoder::segtree<int, makefn(min), [] { return MAX_INT; }>;
void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<int> real_ele;
	vector<int> base(2 * n, MAX_INT);
	for (int i = 0; i < n; i++) { base[i] = a[i]; }
	int actual_size = n - 1;
	SegMin seg = SegMin(base);
	for (int i = 0; i < n; i++) {
		int minimal = seg.prod(i+1, actual_size+1);
		if (minimal < a[i]) {
			real_ele.push_back(a[i] + 1);
			actual_size++;
			seg.set(actual_size, a[i] + 1);
		} else {
			real_ele.push_back(a[i]);
		}
	}
	sort(real_ele.begin(), real_ele.end());
	for (int i = 0; i < real_ele.size(); i++) {
		cout << real_ele[i] << " \n"[i == n - 1];
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
