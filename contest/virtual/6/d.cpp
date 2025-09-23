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
	int n, k;
	cin >> n >> k;
	vector<tuple<int, int, int>> g(n);
	for (auto &[a, b, c] : g) { cin >> a >> b >> c; }
	int actual = k;
	priority_queue<pair<int, int>, vector<pair<int, int>>,
	               greater<pair<int, int>>>
	    out;
	queue<tuple<int, int, int>> q;
	for (auto qq : g) { q.push(qq); }
	int moment = 0;
	vector<int> res;
	while (!q.empty()) {
		auto [in_queue, duration, group_size] = q.front();
		q.pop();

		while (actual < group_size) {
			auto [time_removed, group_size] = out.top();
			out.pop();
			moment = max(moment, time_removed);
			actual += group_size;
		}
		moment = max(moment, in_queue);
		out.push({moment + duration, group_size});
		res.push_back(moment);

		actual -= group_size;
	}
	for(auto i: res) {
		cout << i << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
