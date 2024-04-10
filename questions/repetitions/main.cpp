#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string word;
  cin >> word;
  char last_element = 'P';
  int size = 0;
  int counter = 1;
  for (auto i : word) {
    if (i != last_element) {
      if (counter > size) {
        size = counter;
      }
      last_element = i;
      counter = 1;
    } else {
      counter++;
    }
  }
  if (counter > size) {
    size = counter;
  }
  cout << size << endl;

  return 0;
}
