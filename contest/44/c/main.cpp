#include "atcoder/modint.hpp"
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = atcoder::modint;
#define int ll

void solution() {
  atcoder::modint::set_mod(998244353);
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int actual = 1;
  vector<int> by_two(n);
  for (int64_t i = n - 1; i >= 0; i--) {
    if (a[i] == 2) {
      actual *= 2;
    }
    by_two[i] = actual;
  }

  vector<int> pref(n + 1);
  vector<int> prefones(n + 1);
  for (int64_t i = 1; i <= n; i++) {
    prefones[i] = prefones[i - 1] + (a[i - 1] == 1);
  }

  for (int64_t i = n - 1; i >= 0; i--) {
    pref[i] = pref[i + 1];
    if (a[i] == 1) {
      pref[i] += (by_two[i]);
    }
  }

  int counter = 0;
  for (int64_t i = 2; i < n; i++) {
    if (a[i] == 3) {
      int acc = pref[0] - pref[i];
      acc /= by_two[i];
      counter += acc;

      counter -= prefones[i + 1];
    }
  }
  cout << counter.val() << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int64_t t;
  cin >> t;
  while (t--) {

    solution();
  }

  return 0;
}
