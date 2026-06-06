#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
using vi = vector<i32>;
#define int i64
#define endl '\n'
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
    if (cnt == 1) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    queue<int> q;
    int first = 0, second = -1;
    for (int i = 1; i < n; i++) {
        if (comp[i] != comp[first]) {
            second = i;
            break;
        }
    }
    q.push(first);
    vector<int> acessed(n);
    acessed[first] = true;

    while (!q.empty()) {
        int actual = q.front();
        q.pop();
        for (int next : adj[actual]) {
            if (!acessed[next]) {
                acessed[next] = true;
                q.push(next);
            }
        }
    }
    if (acessed[second]) {
        swap(first, second);
    }
    int actual = second;
    first++, second++;
    cout << format("{} {}\n", first, second);
}
