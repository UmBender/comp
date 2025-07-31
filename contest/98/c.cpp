// clang-format off
//#include <atcoder/all>
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> ab(n);
	vector<map<int, int>> adj(2 * n + 1);
	for (auto &i : ab) {
		cin >> i.first.first >> i.first.second;
		i.first.first--, i.first.second--;
	}

	for (int i = 0; i < n; i++) {
		ab[i].second = i;
		adj[ab[i].first.first][ab[i].first.second] = i + 1;
		adj[ab[i].first.second][ab[i].first.first] = i + 1;
	}
	sort(ab.begin(), ab.end());

	vector<bool> acessed(2 * n + 1);
	set<int> poss;
	for (int i = 0; i < acessed.size(); i++) {
		if (acessed[i]) { continue; }
		queue<int> actual;
		actual.push(i);
		while (!actual.empty()) {
			int nodenow = actual.front();
			actual.pop();
			for (auto [next, sett] : adj[nodenow]) {
				if (!poss.count(sett) && !acessed[next]) {
					poss.insert(sett);
					acessed[next] = true;
					actual.push(next);
				}
			}
		}
	}
	cout << poss.size() << endl;
	vector<int> result;
	for (int val : poss) { result.push_back(val); }
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " \n"[result.size() - 1 == i];
	}
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
