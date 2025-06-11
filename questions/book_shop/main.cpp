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
    int n, x;
    cin >> n >> x;
    vector<int> costs(n);
    vector<int> pages(n);
    for (auto &i : costs) {
        cin >> i;
    }
    for (auto &i : pages) {
        cin >> i;
    }
    vector<int> dp(x + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x - costs[i]; j >= 0; j--) {
            if (dp[j] == -1)
                continue;
            if (costs[i] + j >= x + 1) {
                continue;
            }
            if (dp[j + costs[i]] == -1) {
                dp[j + costs[i]] = dp[j] + pages[i];
            }
            dp[j + costs[i]] = max(dp[j + costs[i]], dp[j] + pages[i]);
        }
    }
    int mmax = 0;
    for (auto i : dp) {
        mmax = max(mmax, i);
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
