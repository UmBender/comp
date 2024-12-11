#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

#define MAX_INT ((int)1E18 + 1000)

int bs(int l, int r, int k) {
  int left = l;
  int right = r;
  int m;
  while (left <= right) {
    m = left + (right - left) / 2;
    if (m * k > r) {
      right = m - 1;
      continue;
    }
    if (m * k <= r && (m + 1) * k > r) {
      return m - l + 1;
    }
    left = m + 1;
  }
  return -1;
}
void solution() {
  int l, r, k;
  cin >> l >> r >> k;
  int result = bs(l, r, k);
  if (result == -1) {
    cout << 0 << endl;

  } else {
    cout << result << endl;
  }
}

int32_t main() {
  int t{0};
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
