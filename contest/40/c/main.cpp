#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m);
  vector<int> q(k);
  set<int> know;
  for (auto &i : a)
    cin >> i;
  for (auto &i : q) {
    cin >> i;
    know.insert(i);
  }
  if (n - k >= 2) {
    for (int i = 0; i < m; i++) {
      cout << '0';
    }
    cout << endl;
    return;
  }
  if (n - k == 1) {
    for (int i = 0; i < m; i++) {
      if (know.count(a[i])) {
        cout << '0';
      } else {
        cout << '1';
      }
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < m; i++) {
    cout << '1';
  }
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
