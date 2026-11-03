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
#define int ll

constexpr ll MOD = 1e9 + 7;

struct Mint {
    int a;
};

Mint e() { return {0}; }
Mint op(Mint f, Mint s) { return {(f.a + s.a) % MOD}; }

// Title: Segment tree
// Description: Generic segment tree over a monoid (op as a lambda): point set, range query, binary
// search. Usage:
//   Segtree seg(n, e, op);   Segtree seg(a, e, op);       // e = identity, op associative
//   Segtree seg(a, 0LL, [](long long x, long long y) { return x + y; });            // sum
//   Segtree seg(n, INT_MAX, [](int x, int y) { return min(x, y); });                // min
//   seg.set(i, x);  seg.get(i);  seg.query(l, r) (op over [l, r), e if empty);  seg.all();
//   seg.maxRight(l, pred)  largest r with pred(query(l, r)); pred(e) must be true, pred monotone
//   seg.minLeft(r, pred)   smallest l with pred(query(l, r))
//   Types must match: e's type is the value type (write 0LL, not 0, for long long).
//   Plain sum / min / max trees: the sum, min, max variants in the <leader>rl menu.
// Complexity: O(log n) per operation, O(n) build.
// Verify: https://judge.yosupo.jp/problem/point_set_range_composite
template <class T, class Op> struct Segtree {
    int n, sz;
    T e;
    Op op;
    vector<T> t;
    Segtree(int n_, T e_, Op op_) : Segtree(vector<T>(n_, e_), e_, op_) {}
    Segtree(const vector<T> &a, T e_, Op op_) : n((int)a.size()), sz(1), e(e_), op(op_) {
        while (sz < n) sz *= 2;
        t.assign(2 * sz, e);
        for (int i = 0; i < n; i++) t[sz + i] = a[i];
        for (int i = sz - 1; i >= 1; i--) pull(i);
    }
    void pull(int i) { t[i] = op(t[2 * i], t[2 * i + 1]); }
    void set(int i, T x) {
        t[i += sz] = x;
        while (i >>= 1) pull(i);
    }
    T get(int i) const { return t[i + sz]; }
    T all() const { return t[1]; }
    T query(int l, int r) {
        T sl = e, sr = e;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sl = op(sl, t[l++]);
            if (r & 1) sr = op(t[--r], sr);
        }
        return op(sl, sr);
    }
    template <class P> int maxRight(int l, P pred) {
        if (l == n) return n;
        l += sz;
        T s = e;
        do {
            while (l % 2 == 0) l >>= 1;
            if (!pred(op(s, t[l]))) {
                while (l < sz) {
                    l = 2 * l;
                    if (pred(op(s, t[l]))) s = op(s, t[l++]);
                }
                return l - sz;
            }
            s = op(s, t[l++]);
        } while ((l & -l) != l);
        return n;
    }
    template <class P> int minLeft(int r, P pred) {
        if (r == 0) return 0;
        r += sz;
        T s = e;
        do {
            r--;
            while (r > 1 && r % 2) r >>= 1;
            if (!pred(op(t[r], s))) {
                while (r < sz) {
                    r = 2 * r + 1;
                    if (pred(op(t[r], s))) s = op(t[r--], s);
                }
                return r + 1 - sz;
            }
            s = op(t[r], s);
        } while ((r & -r) != r);
        return 0;
    }
};

// End: Segment tree

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    auto seg = Segtree(n, e(), op);
    map<int, vector<int>> mp;
    vector<int> cp = x;
    sort(begin(cp), end(cp));
    for (int i = 0; i < n; i++) { mp[cp[i]].push_back(i); }
    for (auto &[k, v] : mp) { reverse(begin(v), end(v)); }
    for (int i = 0; i < n; i++) {
        int actualPos = mp[x[i]].back();
        mp[x[i]].pop_back();
        int range = lower_bound(begin(cp), end(cp), x[i]) - begin(cp);
        Mint total = op(seg.query(0, range), Mint{1});
        seg.set(actualPos, total);
    }
    cout << seg.query(0, n).a << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
