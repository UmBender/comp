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
#define int ll
//using mint = atcoder::modint;
// clang-format on

void solution() {
    int n, h, m;
    cin >> n >> h >> m;
    vector<pair<int, int>> monsters(n);
    for (auto &[ai, bi] : monsters) {
        cin >> ai >> bi;
    }
    vector<vector<int>> dp(n + 1, vector<int>(h + 1, -1));
    dp[0][h] = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            dp[i + 1][j] = max(dp[i][j] - monsters[i].second, dp[i + 1][j]);
            if (j + monsters[i].first <= h) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j + monsters[i].first]);
            }
        }
    }
    int mmax = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= h; j++) {
            if (dp[i][j] >= 0) {
                mmax = max(mmax, i );
            }
        }
    }
	cout << mmax << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
