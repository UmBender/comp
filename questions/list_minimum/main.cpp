#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

int32_t main() {
  int dasize = 0;
  cin >> dasize;
  vector<int> elements;
  while (dasize > 0) {
    int val;
    cin >> val;
    elements.push_back(val);
    dasize--;
  }
  sort(elements.begin(), elements.end());
  int pos = 0;
  while (pos < elements.size()) {
    cout << elements[pos] << '\n';
    pos++;
  }

  return 0;
}
