#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution() {
  int n;
  cin >> n;
  string word;
  cin >> word;
  vector<int> a;
  for (char &i : word) {
    if (i == '0') {
      a.push_back(0);
    } else {
      a.push_back(1);
    }
  }
  int older = -1;
  int count = 0;
  int inner_count = 0;
  bool find_a = false;
  for (auto i : a) {
    if (i == 0) {
      if (older != 0) {
        count--;
        older = 0;
      }
    }
    if (i == 1) {
      count++;
      older = 1;
    }
  }
  cout << ((count > 0) ? "YES" : "NO") << endl;
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
