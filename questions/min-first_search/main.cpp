#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
template <typename... T> void _dbg(const char *names, T &&...args) {
    cerr << "[" << names << "] =";
    ((cerr << ' ' << args), ...);
    cerr << endl;
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;
constexpr ll MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<ll> sp, pos, dp(n);
    sp.push_back(1), pos.push_back(0), dp[0] = 1;
    for (int i = 1; i < n; i++) {
        while (!sp.empty() && sp.back() < p[i]) {
            sp.pop_back();
            pos.pop_back();
        }
        if (sp.empty()) {
            sp.push_back(p[i]);
            pos.push_back(i);
            dp[i] = dp[i - 1] * i;
            dp[i] %= MOD;
            continue;
        }
        int actual = pos.back();
        int diff = i - actual;
        dp[i] = dp[i - 1] * diff;
        dp[i] %= MOD;
        sp.push_back(p[i]);
        pos.push_back(i);
    }
    cout << dp[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
