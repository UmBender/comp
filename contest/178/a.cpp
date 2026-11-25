#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<ll>;
using vvi = vector<vi>;
constexpr int minf = -1e9;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vvi adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (auto &v : adj) { sort(begin(v), end(v)); }
    auto delta = [&](int v, int u) -> int {
        int up = (v < u) ? adj[v].size() : 0;
        int down = lower_bound(begin(adj[v]), end(adj[v]), u) - begin(adj[v]);
        return up - down;
    };

    vi parent(n, -1), color(n, 0), ord, visited(n, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty()) {
        int actual = q.front();
        q.pop();
        ord.push_back(actual);
        for (int w : adj[actual])
            if (!visited[w]) {
                visited[w] = 1;
                parent[w] = actual;
                color[w] = color[actual] ^ 1;
                q.push(w);
            }
    }

    vi d(n, minf);
    d[0] = 0;
    for (int u : ord) {
        int ref = (u != 0) ? parent[u] : adj[0][0];
        if (d[ref] == minf) { d[ref] = 0; }
        int alvo = d[ref] + delta(ref, u);
        for (int v : adj[u]) {
            if (d[v] == minf) { d[v] = alvo - delta(v, u); }
        }
    }

    for (int p = 0; p < 2; p++) {
        int mn = 1e9;
        for (int v = 0; v < n; v++) {
            if (color[v] == p) { mn = min(mn, d[v]); }
        }
        for (int v = 0; v < n; v++) {
            if (color[v] == p) { d[v] += n - mn; }
        }
    }

    for (int v = 0; v < n; v++) { cout << d[v] << " \n"[v == n - 1]; }

    return 0;
}
