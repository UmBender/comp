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
  int m, a, b, c;
  cin >> m >> a >> b >> c;
  int first_row = m, second_row = m;
  int counter = min(first_row, a);
  first_row -= min(first_row, a);
  counter += min(second_row, b);
  second_row -= min(second_row, b);
  int rest = first_row + second_row;
  counter += min(rest, c);
  



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
