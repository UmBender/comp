#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> counter;
  for (auto &i : a) {
    cin >> i;
  }
  if (a[0] > a[1]) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 1; i < n - 1; i++) {
    a[i] -= a[i - 1];
    a[i - 1] = 0;
    if (a[i] > a[i + 1]) {
      cout << "NO" << endl;
      return;
    }
  }
  a[n - 1] -= a[n - 2];
  a[n - 2] = 0;
  cout << "YES" << endl;

  cout << endl;
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
