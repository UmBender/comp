// clang-format off
//#include <atcoder/all>
#include <algorithm>
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
    void increment(int64_t pos, int64_t tl, int64_t tr, int64_t value_pos) {
        if (tl == tr) {

            tree[pos]++;
            return;
        }

        int64_t tm = (tl + tr) / 2;
        if (tm >= value_pos) {
            increment(pos * 2, tl, tm, value_pos);
        } else {
            increment(pos * 2 + 1, tm + 1, tr, value_pos);
        }

        tree[pos] = Comp(tree[pos * 2], tree[pos * 2 + 1]);
    }
    void increment(int64_t value_pos) {
        increment(1, 0, a.size() - 1, value_pos);
    }
    void decrement(int64_t pos, int64_t tl, int64_t tr, int64_t value_pos) {
        if (tl == tr) {

            tree[pos]--;
            return;
        }

        int64_t tm = (tl + tr) / 2;
        if (tm >= value_pos) {
            decrement(pos * 2, tl, tm, value_pos);
        } else {
            decrement(pos * 2 + 1, tm + 1, tr, value_pos);
        }

        tree[pos] = Comp(tree[pos * 2], tree[pos * 2 + 1]);
    }
    void decrement(int64_t value_pos) {
        decrement(1, 0, a.size() - 1, value_pos);
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
using ST = SegTree<int, makefn([](int a, int b) { return a + b; }), []() {
    return 0;
}>;

int bs(vector<int> &a, int val) {
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == val) {
            return m;
        }
        if (a[m] > val) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

void solution() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<pair<char, pair<int, int>>> queries(q);
    vector<int>                        salaries;
    for (auto &i : queries) {
        cin >> i.first >> i.second.first >> i.second.second;
        salaries.push_back(i.second.second);
    }

    for (int i : a) {
        salaries.push_back(i);
    }
    sort(salaries.begin(), salaries.end());
    salaries.erase(unique(salaries.begin(), salaries.end()), salaries.end());

    vector<int> index_salaries(salaries.size());
    vector<int> salaries_counter(index_salaries.size());
    for (int i = 0; i < a.size(); i++) {
        int pos = bs(salaries, a[i]);
        salaries_counter[pos]++;
    }
    ST st = ST(salaries_counter);
    for (auto [opt, vals] : queries) {
        if (opt == '!') {
            auto [employee, value] = vals;
            int old_pos            = bs(salaries, a[employee - 1]);
            a[employee - 1]        = value;
            st.decrement(old_pos);
            int new_pos = bs(salaries, value);
            st.increment(new_pos);
        }
        if (opt == '?') {
            auto [a, b] = vals;
            auto left =
                lower_bound(salaries.begin(), salaries.end(), a);
            auto right =
                upper_bound(salaries.begin(), salaries.end(), b);
            if (right == salaries.begin()) {
                cout << 0 << endl;
                continue;
            }
            if (left ==salaries.end()) {
                cout << 0 << endl;
                continue;
            }
            right--;
            int l = left - salaries.begin();
            int r = right - salaries.begin();
            cout << st.query(l, r) << endl;
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
