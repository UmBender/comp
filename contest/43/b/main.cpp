// #include <atcoder/all>
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  if (n <= 2) {
    cout << n << endl;
    return;
  }

  if (n == 3 || n == 4) {
    cout << 2 << endl;
    return;
  }

  int last = 4;
  int ops = 2;
  while (last < n) {
    last += 1;
    last *= 2;
    ops++;
  }
  cout << ops << endl;
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
