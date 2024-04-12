#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int a[110];
int b[110];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b, b + m);

  int k, l;
  k = n - 1;
  l = m - 1;

  int counter = 0;
  while (k >= 0 && l >= 0) {
    if (abs(a[k] - b[l]) <= 1) {
      counter++;
      k--;
      l--;
    } else {
      if (a[k] > b[l]) {
        k--;
      } else {
        l--;
      }
    }
  }
  cout << counter << '\n';
  return 0;
}
