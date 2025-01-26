#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)

struct SegTree {
  vector<int64_t> a;
  vector<int64_t> tree;
  SegTree(vector<int64_t> &a) : a(a), tree(a.size() * 4) {
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

    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
  }

  void update(int64_t pos, int64_t tl, int64_t tr, int64_t val_pos,
              int64_t val) {
    if (tl == tr) {
      tree[pos] = val;
      return;
    }

    int64_t tm = (tl + tr) / 2;

    if (val_pos <= tm) {
      update(pos * 2, tl, tm, val_pos, val);
    } else {
      update(pos * 2 + 1, tm + 1, tr, val_pos, val);
    }

    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
  }

  void update(int64_t pos, int64_t val) {
    update(1, 0, a.size() - 1, pos, val);
  }

  int64_t query(int64_t pos, int64_t tl, int64_t tr, int64_t n_elem,
                int64_t acc) {
    if (tl == tr)
      return tl;

    int64_t tm = (tl + tr) / 2;
    if(tree[pos * 2] + acc < n_elem) {
      return query(pos * 2 + 1, tm + 1, tr, n_elem, acc + tree[pos * 2]);
    }

    return query(pos * 2, tl, tm, n_elem, acc);
  }
  inline int64_t query(int64_t n_elem) {
    return query(1, 0, a.size() - 1, n_elem, 0);
  }
};

void solution() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  vector<int64_t> pos(n, 1);
  for (int64_t &i : a)
    cin >> i;

  SegTree st(pos);
  vector<int64_t> result(n);
  for (int i = 0; i < n; i++) {
    int64_t pos_element;
    cin >> pos_element;
    int64_t element = st.query(pos_element);
    result[i] = a[element];
    st.update(element, 0);
  }
  for (int64_t i{0}; i < n; i++) {
    cout << result[i] << " \n"[i == n - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
