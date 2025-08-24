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
	inline void update(int val, int l, int r) {
		update(val, l);
		update(-val, r + 1);
	}
	void update(int val, int l) {
		l++;
		for (; l < t.size(); l += (-l & l)) { t[l] += val; }
	}

	int query(int pos) {
		int acc = 0;
		pos++;
		for (; pos > 0; pos -= (pos & -pos)) { acc += t[pos]; }
		return acc;
	}
};
void solution() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	map<int, vector<int>> pos;
	for (int i = 0; i < n; i++) { pos[a[i]].push_back(i); }
	for (auto &[i, j] : pos) { sort(j.begin(), j.end()); }
	set<pair<pair<int, int>, int>> points;
	vector<int> result(n);
	map<int, int> mmax;
	int last = -1;
	BIT bit(n);
	for (auto &[i, j] : pos) {
		if (i - last != 1) { break; }
		priority_queue<pair<pair<int, int>, int>,
		               std::vector<pair<pair<int, int>, int>>,
		               std::greater<pair<pair<int, int>, int>>>
		    actual_points;
		for (auto l : points) { actual_points.push(l); }
		for (int k : j) { actual_points.push({{k, k}, i}); }
		points.clear();

		set<pair<int, int>> pp;
		while (actual_points.size() > 1) {
			auto first = actual_points.top();
			actual_points.pop();
			if (actual_points.top().first.first == first.first.second + 1) {

				pair<pair<int, int>, int> second = {
				    make_pair(first.first.first,
				              actual_points.top().first.second),
				    max(first.second, actual_points.top().second)};
				actual_points.pop();
				actual_points.push(second);
			} else {
				if (first.second == i) { pp.insert(first.first); }
				points.insert(first);
			}
		}
		auto first = actual_points.top();
		actual_points.pop();

		if (first.second == i) { pp.insert(first.first); }
		points.insert(first);
		int mmax_size = 0;
		for (auto l : pp) {
			mmax_size = max(mmax_size, l.second - l.first + 1);
		}
		mmax[i] = mmax_size;
		last = i;
	}

	int last_value = MAX_INT;
	for (int i = 0;; i++) {

		if (mmax[i] == 0) { break; }
		last_value = min(mmax[i], last_value);
		bit.update(1, 0, last_value - 1);
	}
	vector<int> builded(n);
	for (int i = 0; i < n; i++) { builded[i] = bit.query(i); }
	for (int i = 0; i < n; i++) { cout << builded[i] << " \n"[i == n - 1]; }
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
