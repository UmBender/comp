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

using minHeap = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; i++) { sort(begin(adj[i]), end(adj[i])); }
    minHeap pq;
    pq.emplace(0, s);
    vector<ll> dists(n, 1e18);
    dists[s] = 0;
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dists[node] > dist) { continue; }
        if (adj[node].size()) {
            if (dists[adj[node][0]] > dist) {
                dists[adj[node][0]] = dist;
                pq.emplace(dist, adj[node][0]);
            }
        }
        for (int i = 1; i < adj[node].size(); i++) {
            if (dists[adj[node][i]] > dist + 1) {
                dists[adj[node][i]] = dist + 1;
                pq.emplace(dist + 1, adj[node][i]);
            }
        }
    }
    if (dists[t] == 1e18) {
        cout << -1 << endl;
        return;
    }
    cout << dists[t] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
