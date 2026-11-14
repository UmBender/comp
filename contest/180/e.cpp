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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int &ai : a) cin >> ai;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    vector<int> nums = pref;
    for (int i = 0; i <= n; i++) {
        nums.push_back(pref[i] - l);
        nums.push_back(pref[i] - r);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(begin(nums), end(nums)), end(nums));
    auto comp = [&](int val) -> int {
        return lower_bound(begin(nums), end(nums), val) - begin(nums);
    };
    int acc = 0;
    Fenwick<int> bit(nums.size());
    bit.add(comp(0), 1);

    for (int i = 0; i < n; i++) {
        acc += bit.sum(comp(pref[i + 1] - r), comp(pref[i + 1] - l) + 1);
        bit.add(comp(pref[i + 1]), 1);
    }
    cout << acc << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
