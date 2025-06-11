#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  vector<int> c(n);
  for (int i{0}; i < n; ++i) {
    c[i] = a[i] - b[i];
  }

  stable_sort(c.begin(), c.end());

  if (c[0] >= 0) {
    cout << "YES" << endl;
    return;
  }

  if (c[0] < 0 && c[1] + c[0] >= 0) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
