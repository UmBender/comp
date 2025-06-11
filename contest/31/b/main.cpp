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

void solution() {
  int n, d;
  cin >> n >> d;
  vector<int> divisor = {1};
  if (!(d % 3) || n >= 3) {
    divisor.push_back(3);
  }
  if (d == 5) {
    divisor.push_back(5);
  }
  if (d == 7 || n >= 3) {
    divisor.push_back(7);
  }
  if (d == 9 || n >= 6 || (d % 3 == 0 && n >= 3)) {
    divisor.push_back(9);
  }
  for (int i = 0; i < divisor.size(); i++) {
    cout << divisor[i] << " \n"[i == divisor.size() - 1];
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
