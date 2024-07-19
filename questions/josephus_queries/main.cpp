#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int test(int k, int n) {
  if (n == 1) {
    return 1;
  }
  if (2 * k <= (n + 1)) {
    if (2 * k > n) {
      return (2 * k) % n;
    }
    return 2 * k;
  }

  int removed_lower = test(k - (n + 1) / 2, n / 2);
  if (n % 2 == 0) {
    return 2 * removed_lower - 1;
  }
  return 2 * removed_lower + 1;
}

void solution() {
  int k, n;
  cin >> n >> k;
  cout << test(k, n) << endl;
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
