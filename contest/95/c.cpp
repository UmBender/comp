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
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++) { cin >> x[i] >> y[i]; }
	vector<int> xi(n);
	vector<int> yi(n);
	iota(xi.begin(), xi.end(), 0);
	iota(yi.begin(), yi.end(), 0);
	sort(xi.begin(), xi.end(), [&](int i, int j) { return x[i] < x[j]; });
	sort(yi.begin(), yi.end(), [&](int i, int j) { return y[i] < y[j]; });
	vector<int> quad(n);
	for (int i = 0; i < n / 2; i++) {
		quad[xi[i]] |= 1;
		quad[yi[i]] |= 2;
	}
	set<int> num_quads[4];
	for (int i = 0; i < n; i++) { num_quads[quad[i]].insert(i); }
	vector<pair<int, int>> pairs;
	for (int i = 0; i < 2; i++) {

		auto first = num_quads[i].begin();
		auto second = num_quads[i ^ 3].begin();
		while (first != num_quads[i].end()) {
			pairs.push_back({*first, *second});
			first++;
			second++;
		}
	}
	for (auto i : pairs) { println("{} {}", i.first + 1, i.second + 1); }
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
