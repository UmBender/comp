#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, t, p;
  cin >> n >> t >> p;
  vector<int> l(n);

  for (auto &i : l) {

    cin >> i;
  }
  sort(l.rbegin(), l.rend());

	int val = t-l[p-1] > 0 ? t-l[p-1]:0;
	cout << val << endl;


  return 0;
}
