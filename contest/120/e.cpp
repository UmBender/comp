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
	while(t--)
		solution();
	// clang-format on

	return 0;
}

double dist(pair<double, double> a, pair<double, double> b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt((dx * dx) + (dy * dy));
}

pair<double, double> actual_pos(pair<double, double> begin,
                                pair<double, double> end, double time) {

	double distance = dist(begin, end);
	if (time > distance) { return end; }
	double dx = (end.first - begin.first) * (time / distance);
	double dy = (end.second - begin.second) * (time / distance);
	double actual_x = begin.first + dx ;
	double actual_y = begin.second + dy ;
	return {actual_x, actual_y};
}

void solution() {
	vector<pair<int, int>> sg(4);
	for (auto &[x, y] : sg) { cin >> x >> y; }
	double left = 0, right = min(dist(sg[0], sg[1]), dist(sg[2], sg[3]));
	auto calc_dist = [&](double time) -> double {
		auto first = actual_pos(sg[0], sg[1], time);
		auto second = actual_pos(sg[2], sg[3], time);
		return dist(first, second);
	};

	double mmin = (double) MAX_INT;
	for (int i = 0; i < 40; i++) {

		double m1 = left + ((right - left) / 3.0l);
		double m2 = right - ((right - left) / 3.0l);
		double f1 = calc_dist(m1);
		double f2 = calc_dist(m2);
		mmin =min(mmin, min(f1,f2));

		if (f1 < f2) {
			right = m2;
		} else {
			left = m1;
		}
	}
	left = min(dist(sg[0], sg[1]), dist(sg[2], sg[3]));
	right = max(dist(sg[0], sg[1]), dist(sg[2], sg[3]));

	for (int i = 0; i < 40; i++) {

		double m1 = left + ((right - left) / 3.0l);
		double m2 = right - ((right - left) / 3.0l);
		double f1 = calc_dist(m1);
		double f2 = calc_dist(m2);
		mmin =min(mmin, min(f1,f2));

		if (f1 < f2) {
			right = m2;
		} else {
			left = m1;
		}
	}

	cout << fixed << setprecision(18) << mmin << endl;
}
