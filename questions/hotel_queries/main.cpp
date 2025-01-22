#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

struct SegTree {
  vector<int> a;
  vector<int> tree;
  SegTree(vector<int> &a) : a(a), tree(a.size() * 4) {
    build(1, 0, a.size() - 1);
  }
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
  }

  void update(int pos, int remove) { _update(1, 0, a.size() - 1, pos, remove); }
  void _update(int v, int tl, int tr, int pos, int remove) {
    if (tl == tr) {
      tree[v] -= remove;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      _update(v * 2, tl, tm, pos, remove);
    } else {
      _update(v * 2 + 1, tm + 1, tr, pos, remove);
    }
    tree[v] = max(tree[v * 2 + 1], tree[v * 2]);
  }
  int first_upper(int val) {
    if (tree[1] < val) {
      return -1;
    }
    return query_upper(1, 0, a.size() - 1, val);
  }
  int query_upper(int v, int tl, int tr, int minimum) {
    if (tl == tr) {
      return tl;
    }

    int tm = (tl + tr) / 2;
    if (tree[v * 2] >= minimum) {
      return query_upper(v * 2, tl, tm, minimum);
    }

    return query_upper(v * 2 + 1, tm + 1, tr, minimum);
  }
};

void solution() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto st = SegTree(a);
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    int pos = st.first_upper(q);
    if (pos == -1) {
      cout << 0 << " \n"[i == m - 1];
    } else {
      cout << pos + 1 << " \n"[i == m - 1];
      st.update(pos, q);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
