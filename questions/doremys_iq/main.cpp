#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

vector<int> arr;
int n, q;

void solution() {
  cin >> n >> q;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int l, r;
  l = 0;
  r = n - 1;
  int ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int k = q;
    for (int i = mid; i < n; i++) {
      if (k < arr[i]) {
        k--;
      }
    }
    if (k < 0) {
      l = mid + 1;
    } else {
      r = mid - 1;
      ans = mid;
    }
  }
  string s(n, '0');
  if (ans != -1) {
    int counter = 0;
    for (int i = 0; i < ans; i++) {
      if (arr[i] <= q) {
        s[i] = '1';
      }
    }
    for (int i = ans; i < n; ++i) {
      s[i] = '1';
    }
    cout << s << endl;
  }
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
