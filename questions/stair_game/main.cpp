#include <bits/stdc++.h>

using namespace std;

void solution() {
  int64_t n, acc = 0, result = 0;
  cin >> n;

  vector<int64_t> p(n);
  for (auto &i : p) {
    cin >> i;
  }

  reverse(p.begin(), p.end());

  for (int64_t i = 0; i < n - 1; i++) {
    acc ^= p[i];
    result ^= acc;
	cout << "acc: " << acc << endl;
	cout << "result: " << result << endl;
  }
  if (result) {
    cout << "first" << endl;
  } else {
    cout << "second" << endl;
  }
}

signed main() {
  int64_t t;
  cin >> t;
  while (t--) {
    solution();
  }
}
