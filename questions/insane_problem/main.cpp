#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
using mint = atcoder::modint;

void solution() {
  int k, l1, r1, l2, r2;
  cin >> k >> l1 >> r1 >> l2 >> r2;
  int counter = 0;
  int kn = 1;
  for (int n = 0; r2 / kn >= l1; n++) {
    counter += max(0ll, min(r2 / kn, r1) - max((l2 - 1) / kn + 1, l1) + 1ll);
    kn*=k;
  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
