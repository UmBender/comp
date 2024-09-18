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
  int n, m;
  cin >> n >> m;
  unordered_set<int> hash_older;
  for (int i = 0; i < m; i++) {
    int a;
    char b;
    cin >> a >> b;
    if (b == 'F') {
      cout << "No" << endl;
      continue;
    }

    if (!hash_older.count(a)) {
      cout << "Yes" << endl;
      hash_older.insert(a);
      continue;
    } else {
      cout << "No" << endl;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
