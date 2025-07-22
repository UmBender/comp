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

vector<pair<int, int>> all_poss = {};
void all_poss_gen(vector<int> &actual) {
	if (actual.empty()) { return; }

	vector<pair<int, int>> copy = all_poss;
	int actual_ele = actual.back();
	actual.pop_back();

	for (auto i : copy) {
		all_poss.push_back({i.first * actual_ele, i.second + 1});
	}
	all_poss.push_back({actual_ele, 1});
	all_poss_gen(actual);
}

void solution() {
	int l, r;
	cin >> l >> r;
	int counter = 0;

	for (auto i : all_poss) {
		int value = i.first;
		if (value == 1) { continue; }
		if (i.first > r) { break; }

		int left = (((l + value - 1) / value) - 1) * value;
		int right = (r / value) * value;
		int number = (right - left) / value;
		int parity = (i.second % 2 == 1 ? -1 : 1);

		counter += number * parity;
	}
	cout << counter + r - (l - 1) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	vector<int> p = {2, 3, 5, 7};
	all_poss_gen(p);
	sort(all_poss.begin(), all_poss.end());
	int t;
	cin >> t;
	while (t--) solution();

	return 0;
}
