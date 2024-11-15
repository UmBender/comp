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
  int counter = 0;

  int n;
  cin >> n;
  vector<int> h(n);
  set<int> values;
  for (auto &i : h) {
    cin >> i;
    if (!values.count(i)) {
      values.insert(i);
    }
  }

  int max_counter = 1000;
  for (auto k : values) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
      if (k != h[i]) {
        counter++;
      }
    }
    if (counter < max_counter) {
      max_counter = counter;
    }
  }
  cout << max_counter << endl;
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
