#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> counting_letters(256);
  for (auto i : s) {
    counting_letters[i]++;
  }
  map<char, int> pali_let;
  for (int i = 0; i < 256; i++) {
    if (counting_letters[i] >= 2) {
      pali_let[i] = counting_letters[i];
    }
  }

  return 0;
}
