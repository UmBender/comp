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
	solution();
	// clang-format on

	return 0;
}

void solution() {
	int n;
	cin >> n;
	int x[n];
	for (int &i : x) { cin >> i; }
	map<int, int> min_dist;
	set<int> positions;
	int acc = 0;
	positions.insert(0);
	positions.insert(x[0]);
	min_dist[x[0]] = x[0];
	min_dist[0] = x[0];
	acc += 2 * x[0];
	cout << acc << endl;
	for (int i = 1; i < n; i++) {
		auto next = positions.lower_bound(x[i]);
		if (next == positions.end()) {
			auto before = next;
			before--;
			int dist = x[i] - *before;
			if (dist < min_dist[*before]) {
				acc -= min_dist[*before];
				acc += dist;
				min_dist[*before] = dist;
			}
			acc += dist;
			min_dist[x[i]] = dist;
			positions.insert(x[i]);
		} else {
			auto before = next;
			before--;
			// first
			int dist_first, dist_second;
			{
				int dist = x[i] - *before;
				dist_first = dist;
				if (dist < min_dist[*before]) {
					acc -= min_dist[*before];
					acc += dist;
					min_dist[*before] = dist;
				}
			}
			// second
			{
				int dist = *next - x[i];
				dist_second = dist;
				if (dist < min_dist[*next]) {
					acc -= min_dist[*next];
					acc += dist;
					min_dist[*next] = dist;
				}
			}

			int minimal = min(dist_first, dist_second);
			acc += minimal;
			min_dist[x[i]] = minimal;

			positions.insert(x[i]);
		}
		cout << acc << endl;
	}
}
