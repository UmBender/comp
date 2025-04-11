// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
//using mint = atcoder::modint;
// clang-format on
//
//
struct SegTree {
    vector<int>            a;
    vector<pair<int, int>> tree;
    SegTree(vector<int> &a) : a(a), tree(a.size() * 4, {0, 0}) {
        build(1, 0, a.size() - 1);
    }

    void build(int64_t pos, int64_t tl, int64_t tr) {
        if (tl == tr) {
            tree[pos].first  = a[tl];
            tree[pos].second = max(a[tl], 0LL);

            return;
        }

        int64_t tm = (tl + tr) / 2;
        build(2 * pos, tl, tm);
        build(2 * pos + 1, tm + 1, tr);

        tree[pos] = {tree[pos * 2].first + tree[pos * 2 + 1].first,
                     max(tree[pos * 2].first + tree[pos * 2 + 1].second,
                         tree[pos * 2].second)};
    }

    void update(int64_t pos, int64_t tl, int64_t tr, int64_t value_pos,
                int value) {
        if (tl == tr) {
            tree[pos].first  = value;
            tree[pos].second = max(0LL, value);
            return;
        }

        int64_t tm = (tl + tr) / 2;
        if (tm >= value_pos) {
            update(pos * 2, tl, tm, value_pos, value);
        } else {
            update(pos * 2 + 1, tm + 1, tr, value_pos, value);
        }

        tree[pos].first  = tree[pos * 2].first + tree[pos * 2 + 1].first;
        tree[pos].second = max(tree[pos * 2].first + tree[pos * 2 + 1].second,
                               tree[pos * 2].second);
    }

    inline void update(int64_t value_pos, int value) {
        update(1, 0, a.size() - 1, value_pos, value);
    }

    pair<int, int> query(int64_t pos, int64_t tl, int64_t tr, int64_t l,
                         int64_t r) {
        if (l > r) {
            return {0, 0};
        }

        if (tl == l && tr == r) {
            return tree[pos];
        }

        int64_t        tm   = (tl + tr) / 2;
        pair<int, int> left = query(pos * 2, tl, tm, l, min(tm, r));
        pair<int, int> right =
            query(pos * 2 + 1, tm + 1, tr, max(tm + 1, l), r);

        pair<int, int> term;
        term.first  = left.first + right.first;
        term.second = max(left.second, right.second + left.first);
        return term;
    }

    inline pair<int, int> query(int64_t l, int64_t r) {
        return query(1, 0, a.size() - 1, l, r);
    }
};

void solution() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<pair<int, pair<int, int>>> queries(q);
    for (auto &[i, j] : queries) {
        cin >> i >> j.first >> j.second;
    }
    SegTree st = SegTree(a);
    for (int i = 0; i < q; i++) {
        if (queries[i].first == 1) {
            st.update(queries[i].second.first - 1, queries[i].second.second);
        } else {
            auto result = st.query(queries[i].second.first - 1,
                                   queries[i].second.second - 1);
            cout << result.second << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
