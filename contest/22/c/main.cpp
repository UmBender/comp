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

int recursive(int acc1, int acc2, vector<int> &k) {
  if (!k.empty()) {
    int top = k.back();
    k.pop_back();
    int minimal_value = recursive(acc1 + top, acc2, k);
    minimal_value = min(minimal_value, recursive(acc1, acc2 + top, k));
    k.push_back(top);
    return minimal_value;

  } else {
    return max(acc1, acc2);
  }
}
void solution() {
  int n;
  cin >> n;
  vector<int> k(n);
  for (auto &i : k) {
    cin >> i;
  }
  int minimal_value = recursive(0, 0, k);
  cout << minimal_value << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
