#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  if (n >= 1 && n <= 99) {
    cout << 100 - n << endl;
  } else if (n >= 100 && n <= 199) {
    cout << 200 - n << endl;
  } else if (n >= 200 && n <= 299) {
    cout << 300 - n << endl;
  } else {
    cout << "WTF?" << endl;
  }

  return 0;
}
