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

vector<int> arr(200010);
vector<int> pref(200010);

int f(int x) {
  int counter = 0;
  while (x) {
    counter++;
    x /= 3;
  }
  return counter;
}
void solution() {
  int l, r;
  cin >> l >> r;
  int sum = 2 * (pref[l] - pref[l - 1]);
  sum += pref[r] - pref[l];
  cout << sum << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  arr[0] = 0;
  pref[0] = 0;
  for (int i = 1; i < arr.size(); i++) {
    arr[i] = f(i);
    pref[i] = pref[i - 1] + arr[i];
  }
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
