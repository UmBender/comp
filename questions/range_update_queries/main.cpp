#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

struct SegTree {
  vector<int> a;
  vector<int> tree;
  vector<int> lazy;

  SegTree(vector<int> &a) : a(a), tree(a.size() * 4), lazy(a.size() * 4, 0) {
    build(1, 0, a.size() - 1);
  }

  void build(int pos, int tl, int tr) {
    if (tl == tr) {
      tree[pos] = a[tl];
      return;
    }

    int tm = (tl + tr) / 2;
    build(pos * 2, tl, tm);
    build(pos * 2 + 1, tm + 1, tr);
    tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
  }

  void push(int v) {
    tree[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    tree[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }

  void update(int v, int tl, int tr, int l, int r, int diff) {
    if (l > r) {
      return;
    }
    if (l == tl && r == tr) {
      tree[v] += diff;
      lazy[v] += diff;
      return;
    }

    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), diff);
    update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, diff);

    tree[v] = tree[v * 2] + tree[v * 2 + 1];
  }

  int sum(int pos, int tl, int tr, int l, int r) {
    if (l > r) {
      return 0;
    }

    if (tl == l && tr == r) {
      return tree[pos];
    }

    push(pos);

    int tm = (tl + tr) / 2;
    int left = sum(pos * 2, tl, tm, l, min(r, tm));
    int right = sum(pos * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return left + right;
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
  for(int i =0 ; i< q;i++) {
    int op;
    cin >> op;
    if(op == 2) {
      int k;
      cin >> k;
      cout << st.sum(1, 0, a.size() - 1, k-1, k-1) << endl;

    }else {
      int left, right, val;
      cin >> left >> right >> val;
      st.update(1, 0, a.size() - 1, left -1, right - 1, val);
    }

  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
