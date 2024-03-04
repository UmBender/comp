#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

using ll = long long;
#define int ll
int32_t main() {
  int elements[1005];
  bool used[1005];
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;

    if (n == 1) {
      cout << "-1" << endl;
			t--;
      continue;
    }

    for (int i = 1; i <= n; i++)
      cin >> elements[i];
    for (int i = 1; i <= n; i++)
      used[i] = false;

    for (int i = 1; i <= n - 2; i++) {
      int k = 1;
      while (used[k] || k == elements[i])
        ++k;
      cout << k << " ";
      used[k] = true;
    }
    int a = -1, b = -1;
    for (int i = 1; i <= n; i++)
      if (!used[i]) {
        if (a == -1) {
          a = i;
        } else {
          b = i;
        }
      }
        if (a!=elements[n-1] && b!=elements[n]) cout<<a<<" "<<b<<"\n";
        else cout<<b<<" "<<a<<"\n";
    t--;
  }
  return 0;
}
