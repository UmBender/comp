#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl "\n"

int32_t main() {
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 1; i < n; i++) {
    sum += i;
    sum = sum % k;
    printf("%lld ", i);
  }
	cout << (n - 1) + (k - ((n - 1) % k)) + (k - sum) << endl;

  return 0;
}
