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
struct BIT {
	vector<int> base;
	int s;
	BIT(int size) : base(size + 1), s(size) {}

	void update(int left, int right, int value) {
		update(left, value);
		update(right + 1, -value);
	}
	void update(int p, int value) {
		p++;
		for (; p <= s; p += (-p & p)) { base[p] += value; }
	}
	int query(int p) {
		int acc = 0;
		for (p++; p > 0; p -= (-p & p)) { acc += base[p]; }
		return acc;
	}
};

int p[3010];
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
	vector<pair<int, int>> lr(m);
	for (auto &[first, second] : lr) { cin >> first >> second; }
	mkunique(lr);
	BIT bit(n + 1);
	for (auto [l, r] : lr) { bit.update(l, r, 1); }
	int counter[n + 1];
	for (int i = 1; i <= n; i++) { counter[i] = bit.query(i); }
	auto find_zero = [&]() -> int {
		int fm = lr.size();
		for (int i = 1; i <= n; i++) {
			if (counter[i] == fm) { return i; }
		}
		return 0;
	};
	int fm = find_zero();
	if (fm) {
		p[fm] = 0;
		int val = 1;
		for (int i = 1; i <= n; i++) {
			if (i != fm) { p[i] = val++; }
		}
		for (int i = 1; i <= n; i++) { cout << p[i] << " \n"[i == n]; }
		return;
	}

	auto is_inside = [](int p1, int p2, int il, int ir) -> bool {
		if (p1 >= il && p2 <= ir) { return true; }
		return false;
	};

	for (int i = 1; i <= n; i++) {
		if (counter[i] == 0) {
			p[i] = 0;
			int acc = 1;
			for (int j = 1; j <= n; j++) {
				if (j != i) { p[j] = acc++; }
			}
			for (int j = 1; j <= n; j++) { cout << p[j] << " \n"[j == n]; }
			return;
		}
	}

	for (int i = 1; i < n; i++) {
		int co = 0;
		bool okay = true;
		for (auto [left, right] : lr) {
			if (left <= i && i <= right) {
				co++;
				okay &= is_inside(i, i + 1, left, right);
			}
			if (!okay) { break; }
		}
		int first = i, second = i + 1;
		if (okay && co) {
			p[first] = 0;
			p[second] = 1;
			int acc = 2;
			for (int j = 1; j <= n; j++) {
				if (j != first && j != second) { p[j] = acc++; }
			}
			for (int j = 1; j <= n; j++) { cout << p[j] << " \n"[j == n]; }
			return;
		}
		co = 0;
		okay = true;
		for (auto [left, right] : lr) {
			if (left <= i + 1 && i + 1 <= right) {
				co++;
				if (left > i || right < i) { okay = false; }
			}
			if (!okay) { break; }
		}
		first = i + 1, second = i;
		if (okay && co) {
			p[first] = 0;
			p[second] = 1;
			int acc = 2;
			for (int j = 1; j <= n; j++) {
				if (j != first && j != second) { p[j] = acc++; }
			}
			for (int j = 1; j <= n; j++) { cout << p[j] << " \n"[j == n]; }
			return;
		}
	}
	p[1] = 0;
	p[n] = 1;
	for (int i = 2; i < n; i++) { p[i] = i; }
	for (int i = 1; i <= n; i++) { cout << p[i] << " \n"[i == n]; }
}
