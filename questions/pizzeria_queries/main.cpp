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

template <typename T, auto Comp, auto Default> struct SegTree {
    vector<T> a;
    vector<T> tree;
    SegTree(vector<T> &a) : a(a), tree(a.size() * 4, Default()) {
        build(1, 0, a.size() - 1);
    }

    void build(int64_t pos, int64_t tl, int64_t tr) {
        if (tl == tr) {
            tree[pos] = a[tl];
            return;
        }

        int64_t tm = (tl + tr) / 2;
        build(2 * pos, tl, tm);
        build(2 * pos + 1, tm + 1, tr);

        tree[pos] = Comp(tree[pos * 2], tree[pos * 2 + 1]);
    }

    void update(int64_t pos, int64_t tl, int64_t tr, int64_t value_pos,
                T value) {
        if (tl == tr) {
            tree[pos] = value;
            return;
        }

        int64_t tm = (tl + tr) / 2;
        if (tm >= value_pos) {
            update(pos * 2, tl, tm, value_pos, value);
        } else {
            update(pos * 2 + 1, tm + 1, tr, value_pos, value);
        }

        tree[pos] = Comp(tree[pos * 2], tree[pos * 2 + 1]);
    }

    inline void update(int64_t value_pos, T value) {
        update(1, 0, a.size() - 1, value_pos, value);
    }

    T query(int64_t pos, int64_t tl, int64_t tr, int64_t l, int64_t r) {
        if (l > r) {
            return Default();
        }

        if (tl == l && tr == r) {
            return tree[pos];
        }

        int64_t tm    = (tl + tr) / 2;
        T       left  = query(pos * 2, tl, tm, l, min(tm, r));
        T       right = query(pos * 2 + 1, tm + 1, tr, max(tm + 1, l), r);

        return Comp(left, right);
    }

    inline T query(int64_t l, int64_t r) {
        return query(1, 0, a.size() - 1, l, r);
    }
};

using MinSegTree = SegTree<int, makefn(min), []() {
    return MAX_INT;
}>;

void solution() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (auto &i : p) {
        cin >> i;
    }
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
        left[i] = p[i] - i;
    }
    for (int i = n - 1; i >= 0; i--) {
        right[i] = p[i] - (n - 1 - i);
    }
    MinSegTree stleft(left);
    MinSegTree stright(right);
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int pos, value;
            cin >> pos >> value;
            left[pos - 1]  = value - (pos - 1);
            right[pos - 1] = value - (n - 1 - (pos - 1));
            stleft.update(pos - 1, left[pos - 1]);
            stright.update(pos - 1, right[pos - 1]);
        }
        if (opt == 2) {
            int pos;
            cin >> pos;
            pos--;
            int vleft  = stleft.query(0, pos);
            int vright = stright.query(pos, n - 1);
            vleft += pos;
            vright += n - 1 - pos;
            cout << min(vleft, vright) << endl;
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
