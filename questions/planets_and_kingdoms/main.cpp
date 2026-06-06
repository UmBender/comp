#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
using vi = vector<i32>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

pair<int, vi> scc(vector<vi> &g) {
    int n = sz(g);
    vector<vi> rg(n);
    rep(v, 0, n) for (int u : g[v]) rg[u].pb(v);
    vi vis(n), ord, comp(n, -1);
    auto dfs1 = [&](auto self, int v) -> void {
        vis[v] = 1;
        for (int u : g[v])
            if (!vis[u])
                self(self, u);
        ord.pb(v);
    };
    auto dfs2 = [&](auto self, int v, int c) -> void {
        comp[v] = c;
        for (int u : rg[v])
            if (comp[u] < 0)
                self(self, u, c);
    };
    rep(i, 0, n) if (!vis[i]) dfs1(dfs1, i);
    reverse(all(ord));
    int cnt = 0;
    for (int v : ord)
        if (comp[v] < 0)
            dfs2(dfs2, v, cnt++);
    return {cnt, comp};
} // a8c254
signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<i32>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    auto [cnt, comp] = scc(adj);
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << comp[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
