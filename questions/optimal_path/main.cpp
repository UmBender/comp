#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll

void solution() {
  int n, m;
  cin >> n >> m;
  int sol1 = ((1 + m) * m) / 2;
	int sol2 = ((m + m*n) *n) / 2 - m;
	cout << sol1+sol2<<endl;

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    solution();
    t--;
  }

  return 0;
}
