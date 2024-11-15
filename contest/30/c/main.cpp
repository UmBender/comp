#include <bits/stdc++.h>
#include <numeric>

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

vector<int> squares;
void solution() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; i++) {
      cout << i << ' ' << i << ' ';
    }
    cout << endl;
    return;
  }
  if (n % 2 == 1 && n < 27) {
    cout << -1 << endl;
    return;
  }
  vector<int> sup(n, -1);
  sup[0] = 1;
  sup[9] = 1;
  sup[25] = 1;
  sup[1] = 2;
  sup[2] = 2;
  sup[3] = 3;
  sup[4] = 3;
  sup[5] = 4;
  sup[6] = 4;
  sup[7] = 5;
  sup[8] = 5;
  sup[10] = 6;
  sup[11] = 6;
  sup[12] = 7;
  sup[13] = 7;
  sup[14] = 8;
  sup[15] = 8;
  sup[16] = 9;
  sup[17] = 9;
  sup[18] = 10;
  sup[19] = 10;
  sup[20] = 11;
  sup[21] = 11;
  sup[22] = 12;
  sup[26] = 12;
  sup[23] = 13;
  sup[24] = 13;
  int next = 14;
  for (int i = 27; i < n; i += 2) {
    sup[i] = next;
    sup[i + 1] = next;
    next++;
  }
  for (auto i : sup) {
    cout << i << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  for (int i = 1; i * i <= 200100; i++) {
    squares.push_back(i * i);
  }
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
