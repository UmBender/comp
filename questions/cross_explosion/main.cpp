#include <algorithm>
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
  int h, w, q;
  cin >> h >> w >> q;
  int still = h * w;
  vector<set<int>> countl(h), countw(w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      countl[i].insert(j);
      countw[j].insert(i);
    }
  }

  auto clear = [&](int i, int j) {
    still--;
    countl[i].erase(j);
    countw[j].erase(i);
  };
  while (q--) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    if (countl[r].count(c) == 1) {
      clear(r, c);
      continue;
    }
    auto ll = countl[r].lower_bound(c);
    if (ll != begin(countl[r])) {
      ll--;
      clear(r, *ll);
    }
    auto lu = countl[r].upper_bound(c);
    if (lu != end(countl[r])) {
      clear(r, *lu);
    }

    auto rl = countw[c].lower_bound(r);
    if (rl != begin(countw[c])) {
      rl--;
      clear(*rl, c);
    }
    auto ru = countw[c].upper_bound(r);
    if (ru != end(countw[c])) {
      clear(*ru, c);
    }
  }

  cout << still << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
