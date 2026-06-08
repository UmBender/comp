#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int ll
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
mt19937 rng(random_device{}());

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
vector<vi> condGraph(vector<vi> &g, int cnt, vi &comp) {
    vector<vi> dag(cnt);
    rep(v, 0, sz(g)) for (int u : g[v]) if (comp[v] != comp[u]) dag[comp[v]].pb(
        comp[u]);
    rep(i, 0, cnt) {
        sort(all(dag[i]));
        dag[i].erase(unique(all(dag[i])), end(dag[i]));
    }
    return dag;
}
vector<vector<int>> adj;
vector<int> coin;
int n, m;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    coin = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    auto [cnt, comp] = scc(adj);
    map<int, int> compCoins;
    for (int i = 0; i < n; i++) {
        compCoins[comp[i]] += coin[i];
    }
    vector<int> dp(cnt);
    vector<bool> acessed(cnt);
    vector<vector<int>> nAdj = condGraph(adj, cnt, comp);
    function<void(int)> dfs;
    dfs = [&](int actual) {
        dp[actual] = compCoins[actual];
        for (int next : nAdj[actual]) {
            if (!acessed[next]) {
                acessed[next] = true;
                dfs(next);
            }
            dp[actual] = max(dp[actual], compCoins[actual] + dp[next]);
        }
    };
    for (int i = 0; i < cnt; i++) {
        if (!acessed[i]) {
            acessed[i] = true;
            dfs(i);
        }
    }
    int mmax = 0;
    for (int i = 0; i < cnt; i++) {
        mmax = max(mmax, dp[i]);
    }
    cout << mmax << endl;

    return 0;
}
