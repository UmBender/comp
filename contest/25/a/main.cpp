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
  int maxh = 0;
  int maxw = 0;
  vector<pair<int, int>> wh(n);
  for (auto &[i, j] : wh) {
    cin >> i >> j;
    maxh = max(j, maxh);
    maxw = max(i, maxw);
  }
  stable_sort(wh.begin(), wh.end());
  vector<vector<int>> arr(110, vector<int>(110));
  for (int i = 0; i < wh.size(); i++) {
    for (int width = 0; width < wh[i].first; width++) {
      for (int height = 0; height < wh[i].second; height++) {
        arr[height][width] = 1;
      }
    }
  }
  int perimeter = maxh;
  int top = maxh - 1;
  int l = 0;
  while (top > 0) {
    if (arr[top][l]) {
      perimeter += 1;
      l++;
    } else {
      perimeter += 1;
      top--;
    }
  }
  while (arr[0][l]) {
    perimeter += 1;
    l++;
  }
  perimeter += 1;
  perimeter += l;

  cout << perimeter << endl;
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
