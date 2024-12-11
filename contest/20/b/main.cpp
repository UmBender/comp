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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  unordered_map<int, int> counter;
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] - a[i] > 1) {
      int mid_inter = (i + 1) * (n - i - 1);
      counter[mid_inter] += (a[i + 1] - a[i] - 1);
    }

    int intervalos = (i) * ((n - i) - 1);
    intervalos += ((n - i) - 1);
    intervalos += i;
    counter[intervalos]++;
  }
  counter[n - 1]++;

  while (q--) {
    int k;
    cin >> k;
    cout << counter[k] << ' ';
  }
  cout << endl;
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
