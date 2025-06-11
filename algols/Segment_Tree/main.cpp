#include <bits/stdc++.h>
#include <functional>

using namespace std;

#define makefn(fn) [](auto... args) { return fn(args...); }

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

  void update(int64_t pos, int64_t tl, int64_t tr, int64_t value_pos, T value) {
    if (tl == tr) {
      tree[pos] = value;
      return;
    }

    int64_t tm = (tl + tr) / 2;
    if (tm <= value_pos) {
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

    int64_t tm = (tl + tr) / 2;
    T left = query(pos * 2, tl, tm, l, min(tm, r));
    T right = query(pos * 2 + 1, tm + 1, tr, max(tm + 1, l), r);

    return Comp(left, right);
  }

  inline T query(int64_t l, int64_t r) {
    return query(1, 0, a.size() - 1, l, r);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  vector<int64_t> elements = {1, 2, 3, 4, 5, 6, 7, 8};
  auto a = SegTree<int64_t, makefn(max), []() { return 0; }>(elements);
  cout << a.query(0, 7) << endl;

  cout << endl;

  return 0;
}
