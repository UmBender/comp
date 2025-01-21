#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

struct SegTree {
  vector<int> a, t;
  SegTree(vector<int> &a) : a(a), t(4 * a.size()) { build(1, 0, a.size() - 1); }
  void build(int vertex, int tl, int tr) {
    if (tl == tr) {
      t[vertex] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(vertex * 2, tl, tm);
      build(vertex * 2 + 1, tm + 1, tr);
      t[vertex] = t[vertex * 2] + t[vertex * 2 + 1];
    }
  }
  int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
      t[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        update(v * 2, tl, tm, pos, new_val);
      } else {
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      }
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
};

void solution() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto st = SegTree(a);
  for (int s = 0; s < q; s++) {
    int opt, left, right;
    cin >> opt >> left >> right;
    if (opt == 1) {
      st.update(1, 0, st.a.size() - 1, left-1, right);
    }
    if (opt == 2) {
      cout << st.sum(1, 0, st.a.size() - 1, left-1, right-1)<< endl;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
