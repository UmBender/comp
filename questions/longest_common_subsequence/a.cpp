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
    ll n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    ll                 mmax = 0;
    ll                 jmax = 0, lmax = 0;
    for (ll j = 0; j < n; j++) {
        for (ll l = 0; l < m; l++) {
            dp[j][l + 1] = max(dp[j][l], dp[j][l + 1]);
            dp[j + 1][l] = max(dp[j][l], dp[j + 1][l]);
            if (a[j] == b[l]) {
                dp[j + 1][l + 1] = max(dp[j][l] + 1, dp[j + 1][l + 1]);
            }
        }
    }
    for (ll j = 0; j < n + 1; j++) {
        for (ll l = 0; l < m + 1; l++) {
            if (dp[j][l] > mmax) {
                jmax = j;
                lmax = l;
                mmax = max(mmax, dp[j][l]);
            }
        }
    }
    vector<ll> result;
    while (dp[jmax][lmax]) {
        if (lmax && dp[jmax][lmax] == dp[jmax][lmax - 1]) {
            lmax--;
            continue;
        }
        if (jmax && dp[jmax][lmax] == dp[jmax - 1][lmax]) {
            jmax--;
            continue;
        }
        result.push_back(a[jmax - 1]);
        lmax--;
        jmax--;
    }

    cout << mmax << endl;
    reverse(result.begin(), result.end());
    for (ll j = 0; j < mmax; j++) {
        cout << result[j] << " \n"[j == mmax - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
