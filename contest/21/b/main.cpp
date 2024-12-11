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
  string in_order;
  for (char i = 'A'; i <= 'Z'; i++) {
    in_order += i;
  }

  map<char, int> letters;
  string not_order;
  cin >> not_order;
  for (int i = 0; i < not_order.size(); i++) {
    letters[not_order[i]] = i + 1;
  }

  int counter = 0;
  int actual_pos = letters['A'];
  int cost = 0;
  while (counter < 26) {
    cost += abs(letters[in_order[counter]] - actual_pos);
    actual_pos = letters[in_order[counter]];
    counter++;
  }
  cout << cost << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
