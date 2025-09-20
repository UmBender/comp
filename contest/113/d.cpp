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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (auto &i : s) { cin >> i; }
	vector<int> okay(h, 0);
	int black_counter = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				okay[i] |= (1LL << j);
				black_counter++;
			}
		}
	}
	int n_mask = 1LL << w;
	vector<vector<bool>> invalidas(n_mask, vector<bool>(n_mask, false));
	vector<int> dp(n_mask, -MAX_INT);
	for (int m1 = 0; m1 < n_mask; m1++) {
		for (int m2 = 0; m2 < n_mask; m2++) {
			for (int j = 0; j < w - 1; j++) {
				int pattern = (1LL << j) | (1LL << (j + 1));
				if ((m1 & pattern) == pattern && (m2 & pattern) == pattern) {
					invalidas[m1][m2] = true;
					break;
				}
			}
		}
	}

	for (int m0 = okay[0];; m0 = (m0 - 1) & okay[0]) {
		dp[m0] = __builtin_popcount(m0);
		if (m0 == 0) break;
	}

	for (int i = 1; i < h; i++) {
		vector<int> ndp(n_mask, -1);
		for (int m_prev = 0; m_prev < n_mask; m_prev++) {
			if (dp[m_prev] == -1) continue;
			for (int m_curr = okay[i];; m_curr = (m_curr - 1) & okay[i]) {
				if (!invalidas[m_prev][m_curr]) {
					int candidate = dp[m_prev] + __builtin_popcount(m_curr);
					if (candidate > ndp[m_curr]) {
						ndp[m_curr] = candidate;
					}
				}
				if (m_curr == 0) break;
			}
		}
		dp = ndp;
	}

	int mmax = 0;
	for(int i = 0; i < n_mask; i+=1){ 
		if(dp[i] > mmax){
			mmax = dp[i];
			
		}
	}
	cout << black_counter - mmax << endl;
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
