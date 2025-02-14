#include <bits/stdc++.h>
#include <ostream>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  string n;
  cin >> n;
  int acc = 0;
  int six = 0;
  int two = 0;
  for (char i : n) {
    acc += (i - '0');
  }
  for (char i : n) {
    if (i == '2') {
      two++;
    }
    if (i == '3') {
      six++;
    }
  }

  int rest = acc % 9;
  for (int i = 0; i <= two; i++) {
    for (int j = 0; j <= six; j++) {
      if ((rest + i * 2 + j * 6) % 9 == 0) {
        cout << "YES" << endl;
        return;
      }
    }
  }

  cout << "NO" << endl;
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
