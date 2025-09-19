#include <bits/stdc++.h>
using namespace std;

void solution() {
  int64_t n;
  cin >> n;
  int64_t acc = 0;
  while (n--) {
    int64_t xi;
    cin >> xi;
    acc ^= xi;
  }
  if (acc) {
    cout << "first" << endl;
  } else {
    cout << "second" << endl;
  }
}

int32_t main() {
  int64_t t;
  cin >> t;
  while (t--) {
    solution();
  }
}
