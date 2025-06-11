#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

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

int get_max(int i, map<int, int> &max_values) {
  if (max_values.count(i)) {
    return max_values[i];
  }
  if (i <= 3) {
    return 1;
  } else {
    int temp = get_max(i / 4, max_values);
    max_values[i] = temp * 2;
  }
  return max_values[i];
}

void solution() {
  int n;
  map<int, int> max_values;
  cin >> n;
  cout << get_max(n, max_values) << endl;
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
