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

struct BIT {
	vector<int> t;
	BIT(int n) : t(n + 1) {}
	void update(int value, int l, int r) {
		update(value, l);
		update(-value, r + 1);
	}
	void update(int value, int l) {
		l++;
		for (; l < t.size(); l += (-l & l)) { t[l] += value; }
	}
	int query(int pos) {
		int acc = 0;
		pos++;
		for (; pos > 0; pos -= (pos & -pos)) { acc += t[pos]; }
		return acc;
	}
};

void solution() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	vector<pair<int, int>> lr(m);
	for (auto &[l, r] : lr) { cin >> l >> r; }
	BIT bit = BIT(n);
	for (auto [l, r] : lr) { bit.update(1, l - 1, r - 1); }
	vector<int> result(n);
	for (int i = 0; i < n; i++) { result[i] = bit.query(i); }
	for(int i =0; i< n;i++) {
		if(result[i] % 2 == 1) {
			swap(s[i], t[i]);
		}
	}
	cout << s << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
