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
	int n, r;
	cin >> n >> r;
	vector<int> l(n);
	for (auto &i : l) { cin >> i; }
	int left = -1, right = -1;
	for (int i = 0; i < n; i++) {
		if (l[i] == 0) {
			left = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {

		if (l[i] == 0) {
			right = i;
			break;
		}
	}
	if (left == -1) {
		cout << 0 << endl;
		return;
	}
	int counter = 0;

	while (r < left) {
		counter += 2;
		r++;
	}
	while (r - 1 > right) {
		counter += 2;
		r--;
	}
	for (int i = left; i <= right; i++) {
		if (l[i] == 1) { counter++; }
	}
	counter += right - left + 1;
	cout << counter << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
