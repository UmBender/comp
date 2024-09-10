#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

int bs(function<int(int)> f, int target, int upper_bound) {
  int left = 0;
  int right = upper_bound - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (f(middle) == target) {
      return middle;
    }

    if (f(middle) > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

void solution() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  int counter = 0;
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    if (a[i][m - 1] == 'R') {
      counter++;
    }
  }
  for (int i = 0; i < m; i++) {
    if (a[n - 1][i] == 'D') {
      counter++;
    }
  }
  cout << counter << endl;
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
