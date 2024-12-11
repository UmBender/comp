#pragma once
#include <bits/stdc++.h>
using namespace std;
template <class T> class ST {
private:
  vector<T> a;
  vector<T> t;
  void build(int p, int tl, int tr) {
    if (tl == tr) {
      t[p] = a[tl];
      return;
    }

    int tm = (tl + tr) / 2;
    build(p * 2, tl, tm);
    build(p * 2 + 1, tm + 1, tm);
    t[p] = t[2 * p] + t[2 * p + 1];
  }

  int sum(int p, int tl, int tr, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (tl == l && tr == r) {
      return t[p];
    }
    int left, right;
    //
    t[p] = left + right;
  }

public:
  ST(vector<T> &a) : a(a), t(4 * a.size()) { build(1, 0, a.size() - 1); }
};
