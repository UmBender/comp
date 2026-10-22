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

// Title: DSU (union-find)
// Description: Disjoint set union with union by size and path compression; sizes, component count,
// groups. Usage:
//   DSU dsu(n);
//   dsu.unite(a, b)   merges; false if already together
//   dsu.same(a, b);  dsu.find(x);  dsu.size(x) (size of x's set);  dsu.count() (number of sets)
//   dsu.groups()      vector of sets (each a vector of elements)
// Complexity: O(alpha(n)) amortized per operation.
// Verify: https://judge.yosupo.jp/problem/unionfind
struct DSU {
    vector<int> p; // p[x] < 0: x is a root and -p[x] is the size
    int comps;
    DSU(int n = 0) : p(n, -1), comps(n) {}
    int find(int x) {
        int r = x;
        while (p[r] >= 0) r = p[r];
        while (p[x] >= 0) {
            int nxt = p[x];
            p[x] = r, x = nxt;
        }
        return r;
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (p[a] > p[b]) swap(a, b);
        p[a] += p[b], p[b] = a, comps--;
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -p[find(x)]; }
    int count() const { return comps; }
    vector<vector<int>> groups() {
        int n = (int)p.size();
        vector<int> idx(n, -1);
        vector<vector<int>> res;
        for (int x = 0; x < n; x++) {
            int r = find(x);
            if (idx[r] < 0) idx[r] = (int)res.size(), res.emplace_back();
            res[idx[r]].push_back(x);
        }
        return res;
    }
};
// End: DSU (union-find)

void solve() {
    ll n;
    cin >> n;
    vector<ll> x(n), h(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> h[i];
    vector<tuple<ll, ll, ll>> edges;
    set<ll> adds;
    vector<pair<ll, ll>> nodes(n);
    map<ll, ll> comp;
    for (int i = 0; i < n; i++) { comp[x[i]] = i; }

    for (int i = 0; i < n; i++) { nodes[i] = {h[i], x[i]}; }
    sort(begin(nodes), end(nodes));
    for (int i = 0; i < n; i++) {
        auto [actualH, actualX] = nodes[i];
        auto it = adds.lower_bound(actualX);
        if (it != end(adds)) {
            edges.emplace_back(abs(actualX - *it) + actualH, actualX, *it);
            dbg(*it);
        }
        if (it != begin(adds)) {
            it--;
            edges.emplace_back(edges.emplace_back(abs(actualX - *it) + actualH, actualX, *it));
            dbg(*it);
        }
        adds.insert(actualX);
    }
    DSU dsu(n);
    ll ans = 0;
    sort(begin(edges), end(edges));
    dbg(edges.size());
    for (int i = 0; i < edges.size(); i++) {
        auto [cst, first, second] = edges[i];
        dbg(cst, first, second);
        if (dsu.same(comp[first], comp[second])) { continue; }
        ans += cst;
        dsu.unite(comp[first], comp[second]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
