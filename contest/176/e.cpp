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
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

// Title: Tree diameter
// Description: Longest path of a tree (unweighted or with non-negative weights), as a vertex list.
// Usage:
//   vector<int> p = treeDiameter(g);          // g: vector<vector<int>>, diameter = p.size() - 1
//   auto [len, p] = treeDiameter(wg);         // wg: vector<vector<pair<int, T>>> {to, weight >= 0}
//   p goes from one end of the diameter to the other; the center is p[(p.size() - 1) / 2]
//   (unweighted)
// Complexity: O(n).
// Verify: https://judge.yosupo.jp/problem/tree_diameter
template <class T> pair<T, vector<int>> treeDiameter(const vector<vector<pair<int, T>>> &g) {
    int n = (int)g.size();
    vector<T> d(n);
    vector<int> par(n);
    // farthest vertex from s (the farthest from any vertex is an end of a diameter)
    auto farthest = [&](int s) {
        vector<int> st{s};
        d[s] = T(), par[s] = -1;
        int best = s;
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            if (d[v] > d[best]) best = v;
            for (auto [u, w] : g[v])
                if (u != par[v]) d[u] = d[v] + w, par[u] = v, st.push_back(u);
        }
        return best;
    };
    int a = farthest(farthest(0));
    vector<int> path;
    for (int v = a; v != -1; v = par[v]) path.push_back(v);
    return {d[a], path};
}

vector<int> treeDiameter(const vector<vector<int>> &g) {
    vector<vector<pair<int, int>>> wg(g.size());
    for (int v = 0; v < (int)g.size(); v++)
        for (int u : g[v]) wg[v].push_back({u, 1});
    return treeDiameter(wg).second;
}
// End: Tree diameter

void solve() {
    int n;
    cin >> n;

    vvi adj(n);
    vi c(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) cin >> c[i];

    vi path = treeDiameter(adj);

    if (path.size() % 2) {
        int center = path[path.size() / 2];
        vi dist(n);

        vector<map<int, int>> calcs;
        map<int, int> cols;

        auto dfs = [&](int actual, int last) -> void {
            vector<pii> st{{actual, last}};

            while (!st.empty()) {
                auto [v, parent] = st.back();
                st.pop_back();

                if (dist[v] == (int)path.size() / 2) { cols[c[v]]++; }

                for (int next : adj[v]) {
                    if (next == parent) continue;

                    dist[next] = dist[v] + 1;
                    st.push_back({next, v});
                }
            }
        };

        for (int next : adj[center]) {
            dist[next] = 1;
            dfs(next, center);
            calcs.push_back(cols);
            cols.clear();
        }

        map<int, int> total;

        for (auto &mp : calcs) {
            for (auto [k, v] : mp) { total[k] += v; }
        }

        ll acc = 0;

        for (auto &mp : calcs) {
            for (auto [k, v] : mp) { acc += 1LL * (total[k] - v) * v; }
        }

        cout << acc / 2 << endl;
        return;
    }

    int center = path[path.size() / 2];

    vi dist(n, -1);
    dist[center] = 0;

    auto dfs = [&](int actual, int last) -> void {
        vector<pii> st{{actual, last}};

        while (!st.empty()) {
            auto [v, parent] = st.back();
            st.pop_back();

            for (int next : adj[v]) {
                if (next == parent) continue;

                dist[next] = dist[v] + 1;
                st.push_back({next, v});
            }
        }
    };

    dfs(center, path[path.size() / 2 - 1]);

    ll mmax = *max_element(begin(dist), end(dist));
    map<int, int> cols1, cols2;

    for (int i = 0; i < n; i++) {
        if (dist[i] == mmax) { cols1[c[i]]++; }
    }

    fill(begin(dist), end(dist), -1);
    dist[path[path.size() / 2 - 1]] = 0;

    dfs(path[path.size() / 2 - 1], center);

    mmax = *max_element(begin(dist), end(dist));

    for (int i = 0; i < n; i++) {
        if (dist[i] == mmax) { cols2[c[i]]++; }
    }

    ll acc = 0;

    for (auto [k, v] : cols1) {
        ll other = cols2[k];
        acc += v * other;
    }

    cout << acc << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
