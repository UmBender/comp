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
	vector<int> a(n);
	for (auto &i : a) { cin >> i; }
	vector<vector<int>> slices;
	vector<int> actual;
	int actual_type = a.front();
	for (int i = 0; i < n; i++) {
		if (a[i] == actual_type) {
			actual.push_back(i);
		} else {
			slices.push_back(actual);
			actual.clear();
			actual.push_back(i);
			actual_type = a[i];
		}
	}
	slices.push_back(actual);
	vector<int> dp(slices.size() - 1);


	for (int i = 0; i < static_cast<int>(dp.size()); i++) {

		dp[i] = min(slices[i + 1].size(), slices[i].size());
	}
	int mmax = 0;
	for(int i: dp) {
		mmax = max(i, mmax);
	}
	cout << 2 * mmax << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
