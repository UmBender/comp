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
using vi = vector<ll>;

// Title: Fenwick tree
// Description: Point add / prefix and range sums over any additive type (BIT), 0-indexed.
// Usage:
//   Fenwick<long long> fw(n);   Fenwick<long long> fw(a);   // zeros / from a vector in O(n)
//   fw.add(i, x);  fw.set(i, x);  fw.get(i);
//   fw.sum(r)      sum of [0, r)        fw.sum(l, r)   sum of [l, r)
//   fw.lowerBound(s)  smallest r with sum(r) >= s (all values >= 0); n + 1 if none, 0 if s <= 0
//   T defaults to long long: Fenwick fw(n).  Range add + range sum: the range variant.
// Complexity: O(log n) per operation, O(n) build.
// Verify: https://judge.yosupo.jp/problem/point_add_range_sum
template <class T = long long> struct Fenwick {
    int n;
    vector<T> t;
    Fenwick(int n_ = 0) : n(n_), t(n_, T{}) {}
    Fenwick(const vector<T> &a) : n((int)a.size()), t(a) {
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) t[j - 1] += t[i - 1];
        }
    }
    void add(int i, T x) {
        for (i++; i <= n; i += i & -i) t[i - 1] += x;
    }
    T sum(int r) const {
        T s{};
        for (; r > 0; r -= r & -r) s += t[r - 1];
        return s;
    }
    T sum(int l, int r) const { return sum(r) - sum(l); }
    T get(int i) const { return sum(i, i + 1); }
    void set(int i, T x) { add(i, x - get(i)); }
    int lowerBound(T s) const {
        if (!(T{} < s)) return 0;
        int pos = 0, pw = 1;
        while (pw * 2 <= n) pw *= 2;
        for (; pw; pw /= 2)
            if (pos + pw <= n && t[pos + pw - 1] < s) pos += pw, s -= t[pos - 1];
        return pos + 1;
    }
};

// End: Fenwick tree

void solve() {
    ll h, w, n, q;
    cin >> h >> w >> n >> q;
    vi r(n), c(n), coords(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
        coords[i * 2] = r[i];
        coords[i * 2 + 1] = c[i];
    }
    vector<tuple<ll, ll, ll>> qq(q);
    for (auto &[opt, a, b] : qq) {
        cin >> opt >> a >> b;
        coords.push_back(a);
        coords.push_back(b);
    }
    sort(begin(coords), end(coords));
    coords.erase(unique(begin(coords), end(coords)), end(coords));
    auto getComp = [&](ll actual) -> ll {
        ll pos = lower_bound(begin(coords), end(coords), actual) - begin(coords);
        return pos;
    };
    Fenwick<ll> cols(coords.size()), rows(coords.size());
    for (int i = 0; i < n; i++) {
        rows.add(getComp(r[i]), 1ll);
        cols.add(getComp(c[i]), 1ll);
    }
    for (auto [opt, a, b] : qq) {
        if (opt == 1) { cout << rows.sum(getComp(a), getComp(b) + 1) << endl; }
        if (opt == 2) { cout << cols.sum(getComp(a), getComp(b) + 1) << endl; }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
