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

void solution() {
  int n;
  cin >> n;
  vector<int> arr(n);
  int sum = 0;
  for (auto &i : arr) {
    cin >> i;
    sum += i;
  }
  sort(arr.begin(), arr.end());
  if (n == 1 || n == 2) {
    cout << "-1" << endl;
    return;
  }
  int middle_pos = arr.size() / 2;
  int media = arr[middle_pos] * 2;
  cout << max<int>(0, media * arr.size() + 1 - sum) << endl;
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
