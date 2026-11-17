#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;

constexpr int MOD = 1e9 + 7;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vi r(n + 1);
    for (int i = 1; i <= n; i++) { cin >> r[i]; }

    vvi adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vvi dp(n + 1, vi(k, 0));

    auto dfs = [&](auto &&self, int u, int p) -> void {
        bool leaf = true;
        for (int v : adj[u]) {
            if (v != p) {
                leaf = false;
                break;
            }
        }

        if (leaf) {
            dp[u][0] = 1;
            dp[u][1 % k] = (dp[u][1 % k] + 1) % MOD;
        } else {
            dp[u][0] = 1;
            for (int v : adj[u]) {
                if (v != p) {
                    self(self, v, u);
                    vi ndp(k, 0);
                    for (int i = 0; i < k; i++) {
                        for (int j = 0; j < k; j++) {
                            ndp[(i + j) % k] = (ndp[(i + j) % k] + dp[u][i] * dp[v][j]) % MOD;
                        }
                    }
                    dp[u] = ndp;
                }
            }
        }

        if (r[u] != -1) {
            vi ndp(k, 0);
            if (r[u] >= 0 && r[u] < k) { ndp[r[u]] = dp[u][r[u]]; }
            dp[u] = ndp;
        }
    };

    dfs(dfs, 1, 0);

    int ans = 0;
    for (int i = 0; i < k; i++) { ans = (ans + dp[1][i]) % MOD; }

    cout << ans << endl;

    return 0;
}
