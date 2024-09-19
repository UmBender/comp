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
  string s, t;
  cin >> s >> t;
  vector<string> handle;
  while (s != t) {
    vector<string> arr;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != t[i]) {
        string k = s;
        k[i] = t[i];
        arr.push_back(k);
      }
    }
    sort(arr.begin(), arr.end());
    handle.push_back(arr.front());
    s = arr.front();
  }

  cout << handle.size() << endl;
  for (auto &i : handle) {
    cout << i << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
