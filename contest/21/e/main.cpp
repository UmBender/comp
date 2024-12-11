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
  int n, m, k;
  cin >> n >> m >> k;
  set<int> vals;
  vector<int> a(n);
  vector<pair<int, int>> ord;
  int sum = 0;
  int position = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
    ord.push_back(make_pair(i, position));
    position++;
    vals.insert(i);
  }
  sort(ord.rbegin(), ord.rend());
  int pos = 0;
  int amount = ord.front().first;
  int last_amount = ord.front().first;
  int countingdif = 0;
  int actual_count = 0;
  while (actual_count < m && pos < n) {
    if (amount == ord[pos].first) {
      countingdif++;
    } else {
      last_amount = amount;
      amount = ord[pos].first;
      actual_count += countingdif;
      countingdif = 0;
    }
    pos++;
  }

  int target = ord.front().first;

  if (actual_count < m) {
    target = amount;
  } else {
    target = last_amount;
  }
  for ()
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
