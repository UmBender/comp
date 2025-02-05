#include <bits/stdc++.h>
using ll = long long;
#define int ll

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

void solution() {
  int l, r;
  cin >> l >> r;
  if (l == 1 && r == 1) {
    cout << 1 << endl;
    return;
  }
  cout << (r - l) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
