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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    map<pair<int, int>, int> comp;
    map<int, vector<int>> xy, yx;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        xy[x[i]].push_back(y[i]);
        yx[y[i]].push_back(x[i]);
        comp[{x[i], y[i]}] = i;
    }
    auto dsu = DSU(n);
    for (int i = 0; i < n; i++) {
        auto pp = {x[i], y[i]};
        int xx = x[i];
        int yy = y[i];
        for (auto next : xy[xx]) {
            int nextNode = comp[{xx, next}];
            dsu.unite(i, nextNode);
        }
        xy[xx].clear();
        for (auto next : yx[yy]) {
            int nextNode = comp[{next, yy}];
            dsu.unite(i, nextNode);
        }
        yx[yy].clear();
    }
    map<int, vector<int>> groupX, groupY;
    for (int i = 0; i < n; i++) {
        int parent = dsu.find(comp[{x[i], y[i]}]);
        groupX[parent].push_back(x[i]);
        groupY[parent].push_back(y[i]);
    }
    ll total = 0;
    for (auto &[k, v] : groupX) {
        auto &r = groupY[k];
        sort(begin(v), end(v));

        sort(begin(r), end(r));
        v.erase(unique(begin(v), end(v)), end(v));
        r.erase(unique(begin(r), end(r)), end(r));
        total += ll(v.size()) * ll(groupY[k].size());
        dbg(k, groupX[k].size(), groupY[k].size());
    }
    total -= n;
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
