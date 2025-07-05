// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
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

int disc_sqrt(int value) {
	int left = 0;
	int right = 100000000;
	int mmin = right;
	while (left <= right) {
		int middle = left + (right - left) / 2;
		if (middle * middle >= value) {
			mmin = min(middle, mmin);
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}
	return mmin;
}

int pow2(int val) { return val * val; }
void solution() {
	int n;
	cin >> n;
	int px, py, qx, qy;
	cin >> px >> py >> qx >> qy;
	int dist2 = pow2(px - qx) + pow2(py - qy);
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }

	sort(a.rbegin(), a.rend());
	int sum = reduce(a.begin(), a.end(), 0LL);
	int minimal = max(0LL, 2 * a[0] - sum);
	int min2 = pow2(minimal);
	int total2 = sum * sum;
	if(min2 <= dist2 && dist2 <= total2) {
		cout << "Yes" << endl;

	}else{
		cout << "No" << endl;
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
