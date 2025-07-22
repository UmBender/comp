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
	vector<vector<bool>> mat(n, vector<bool>(n));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		mat[a][b] = true;
		mat[b][a] = true;
	}
	vector<int> perms(n);
	iota(perms.begin(), perms.end(), 0LL);
	int mmin = MAX_INT;
	do {
		vector<vector<bool>> base_adj(n, vector<bool>(n));
		for (int i = 0; i < n; i++) {
			base_adj[i][(i + 1) % n] = true;
			base_adj[(i + 1) % n][i] = true;
		}
		int counter = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (base_adj[i][j] != mat[perms[i]][perms[j]]) { counter++; }
			}
		}
		counter /= 2;

		mmin = min(counter, mmin);
		for (int i = 3; i < 6 && (n - i) >= 3; i++) {
			for (int k = 0; k < n; k++)
				fill(base_adj[k].begin(), base_adj[k].end(), false);
			for (int k = 0; k < i; k++) {
				base_adj[k][(k + 1) % i] = true;
				base_adj[(k + 1) % i][k] = true;
			}
			for (int k = i; k < n; k++) {
				int begin = k;
				int end = (k + 1) % n;
				end += (!end ? i : 0);
				base_adj[begin][end] = true;
				base_adj[end][begin] = true;
			}
			counter = 0;
			for (int k = 0; k < n; k++) {
				for (int j = 0; j < n; j++) {
					if (base_adj[k][j] != mat[perms[k]][perms[j]]) {
						counter++;
					}
				}
			}
			counter /= 2;
			mmin = min(counter, mmin);
		}

	} while (next_permutation(perms.begin(), perms.end()));
	cout << mmin << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	// atcoder::modint::set_mod(998244353);
	solution();

	return 0;
}
