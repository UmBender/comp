#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
using mint = atcoder::modint;
#define MOD (int)1e9 + 7

void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int max_count = 0;
  int actual = 0;
  int last_pos = 0;
  for (int i = 0; i < n; i++) {
    actual += a[i];
    if (actual < 0) {
      actual = 0;
    }
    if (actual > max_count) {
      max_count = actual;
      last_pos = i;
    }
  }
  int allsum = 0;
  for (int i = 0; i < n; i++) {
    allsum += a[i];
  }
  while (allsum < 0) {
    allsum += MOD;
  }

  allsum %= MOD;
  allsum += max_count;
  allsum %= MOD;
  k--;
  while (k--) {
    max_count *= 2;
    max_count %= MOD;
    allsum += max_count;
    allsum %= MOD;
  }

  cout << allsum << endl;
  return;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod((int)1e9 + 7);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
