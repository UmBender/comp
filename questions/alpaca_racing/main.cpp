#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int32_t main() {
  int n, d, k, x;
  int p;

  cin >> n >> d >> k >> x;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    a.push_back(ai);
  }
  cin >> p;
  int counter = 0;
  for (int i = 0; i < a.size(); i++) {
    while (a[i] >= p) {
      counter++;
      a[i] = (a[i] * (100.0 - x)) / 100.0;
      if (counter > k) {
          cout << "NO" << endl;
          return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
