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
constexpr ll inf = 1ll << 62;

void solve() {
    int n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<ll>> dp(2, vector<ll>(n));
    vector<int> parent(n, -1), order;
    order.reserve(n);
    order.push_back(0);
    parent[0] = 0;

    for (int i = 0; i < n; i++) {
        int v = order[i];
        for (int u : adj[v]) {
            if (u == parent[v]) { continue; }
            parent[u] = v;
            order.push_back(u);
        }
    }
    ll ans = inf;
    for (int i = n - 1; i >= 0; i--) {
        int v = order[i];
        ll base = 0;
        vector<ll> diff;
        diff.reserve(adj[v].size());

        for (int u : adj[v]) {
            if (u == parent[v]) { continue; }

            base += dp[0][u];

            diff.push_back(dp[1][u] - dp[0][u]);
        }
        sort(begin(diff), end(diff));
        dp[0][v] = inf, dp[1][v] = inf;
        int child = diff.size();
        ll curr = base;

        for (int k = 0; k <= child; k++) {
            ll balance = child - 2LL * k;
            dp[0][v] = min(dp[0][v], curr + max(0LL, balance - 1) * c[v]);
            dp[1][v] = min(dp[1][v], curr + max(0LL, balance + 1) * c[v]);
            if (v == 0) { ans = min(ans, curr + max(0LL, balance) * c[v]); }

            if (k < child) { curr += diff[k]; }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
