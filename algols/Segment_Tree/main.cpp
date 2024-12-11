#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
  vector<int> a;
  vector<int> t;

public:
  SegmentTree(vector<int> &a) : a(a), t(4 * a.size()) {
    build(1, 0, a.size() - 1);
  }
  void build(int vertice_atual, int tl, int tr) {
    if (tl == tr) {
      t[vertice_atual] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(vertice_atual << 1, tl, tm);
      build((vertice_atual << 1) + 1, tm + 1, tr);
      t[vertice_atual] = t[vertice_atual << 1] + t[(vertice_atual << 1) + 1];
    }
  }

  int querry(int l, int r) { return sum(1, 0, a.size() - 1, l, r); }

private:
  int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    int sum_left = sum(v * 2, tl, tm, l, min(r, tm));
    int sum_right = sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return sum_left + sum_right;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8};
  auto a = SegmentTree(elements);
  cout << a.querry(0, 7) << endl;

  cout << endl;

  return 0;
}
