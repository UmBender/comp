// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

[[nodiscard]] int big_bit_pos(int i) {
  int counter = 0;
  while (i) {
    i >>= 1;
    counter++;
  }
  return counter;
}

void solution() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> pref(n + 1);
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] ^ a[i];
  }
  vector<vector<int>> biggest_bit(n, vector<int>(32, 0));
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      biggest_bit[i] = biggest_bit[i - 1];
    }
    biggest_bit[i][big_bit_pos(a[i])] = i;
    for (int j = biggest_bit[i].size() - 2; j >= 0; j--) {
      biggest_bit[i][j] = max(biggest_bit[i][j], biggest_bit[i][j + 1]);
    }
  }

  while (q--) {
    int x;
    cin >> x;
    int pos = n - 1;
    while (pos >= 0 && x > 0) {
      int msb = big_bit_pos(x);
      int next_pos = biggest_bit[pos][msb];
      x ^= pref[pos + 1] ^ pref[next_pos + 1];
      pos = next_pos;
      if (a[next_pos] > x)
        break;
      x ^= a[next_pos];
      pos--;
    }

    cout << n - pos - 1 << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
