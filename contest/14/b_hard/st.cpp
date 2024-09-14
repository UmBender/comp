#include <bits/stdc++.h>

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8};
  auto a = SegmentTree(elements);
  cout << a.querry(0, 7) << endl;

  cout << endl;

  return 0;
}
