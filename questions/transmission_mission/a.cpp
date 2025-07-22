// clang-format off
//#include <atcoder/all>
#include <algorithm>
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
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (auto &i : x) { cin >> i; }
	sort(x.begin(), x.end());
	auto iter = unique(x.begin(), x.end());
	x.erase(iter, x.end());
	vector<pair<int, int>> dist;
	n = static_cast<int>(x.size());
	for (int i = 1; i < n; i++) { dist.push_back({x[i] - x[i - 1], x[i - 1]}); }
	sort(dist.rbegin(), dist.rend());
	if (x.size() <= m) {
		cout << 0 << endl;
		return;
	}
	vector<int> biggest;
	int pos = 0;
	while (biggest.size() < m - 1 && pos < dist.size()) {
		biggest.push_back(dist[pos].second);
		pos++;
	}
	sort(biggest.rbegin(), biggest.rend());
	int actual = x.front();
	int size = 0;
	int acc = 0;

	for (int i = 0; i < n-1 ; i++) {
		size += x[i] - actual;
		actual = x[i];
		if (!biggest.empty() && actual >= biggest.back()) {
			biggest.pop_back();
			acc += size;
			size = 0;
			actual = x[i + 1];
		}
	}
	size += x.back() - actual;
	acc += size;
	cout << acc << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
