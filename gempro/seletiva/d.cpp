#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
#define int i64
const int MOD = 998244353;
void solution() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> ways(n + 1);
    vector<int> sizes(n + 1, 0);

    function<void(int, int)> dfs;

    dfs = [&](int u, int p) -> void {
        sizes[u] = 0;

        vector<array<int, 3>> dp(1, {0, 0, 0});
        dp[0][0] = 1;

        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);

            vector<array<int, 3>> next_dp(sizes[u] + sizes[v] + 1, {0, 0, 0});

            for (int k = 0; k <= sizes[u]; k++) {
                for (int c = 0; c < 3; c++) {
                    if (!dp[k][c]) {
                        continue;
                    }

                    next_dp[k][c] = (next_dp[k][c] + dp[k][c]) % MOD;

                    for (int kv = 1; kv <= sizes[v]; kv++) {
                        if (!ways[v][kv]) {
                            continue;
                        }
                        int nc = min(2ll, c + 1);
                        next_dp[k + kv][nc] = (next_dp[k + kv][nc] +
                                               1LL * dp[k][c] * ways[v][kv]) %
                                              MOD;
                    }
                }
            }
            swap(dp, next_dp);
            sizes[u] += sizes[v];
        }

        sizes[u] += 1;
        ways[u].resize(sizes[u] + 1);
        for (int i = 0; i <= sizes[u]; i++) {
            ways[u][i] = 0;
        }

        for (int k = 0; k <= sizes[u] - 1; k++) {
            for (int c = 0; c < 3; c++) {
                if (!dp[k][c]) {
                    continue;
                }

                if (c == 1) {
                    ways[u][k] = (ways[u][k] + dp[k][c]) % MOD;
                } else if (c == 2) {
                    ways[u][k + 1] = (ways[u][k + 1] + dp[k][c]) % MOD;
                }

                if (c == 0) {
                    ways[u][1] = (ways[u][1] + dp[k][c]) % MOD;
                } else if (c == 1 || c == 2) {
                    ways[u][k + 1] = (ways[u][k + 1] + dp[k][c]) % MOD;
                }
            }
        }
    };

    dfs(1, 0);

    for (int k = 1; k <= n; k++) {
        cout << ways[1][k] << " \n"[k == n];
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
