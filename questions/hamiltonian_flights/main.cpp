#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;
using vi = vector<int>;
using vvi = vector<vi>;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    vi dp(n * (1ll << n));
    dp[n] = 1;

    for (int mask = 1; mask < (1ll << n) - 1; mask += 2) {
        for (int node = 0; node < n; node++) {
            if (!(mask & (1ll << node))) { continue; }
            int base = mask * n;
            for (auto next : adj[node]) {
                if (mask & (1ll << next)) { continue; }
                int nmask = mask | (1ll << next);
                int nbase = nmask * n;
                dp[nbase + next] += dp[base + node];
                dp[nbase + next] %= mod;
            }
        }
    }

    cout << dp[((1ll << n) - 1) * n + (n - 1)] << endl;

    return 0;
}
