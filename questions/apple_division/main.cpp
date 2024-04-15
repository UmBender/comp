#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int p[30];
int n;

int solution(int pos, int sum) {
  if (pos >= n) {
    return sum;
  }
  int new_add = solution(pos + 1, sum + p[pos]);
  int new_sub = solution(pos + 1, sum - p[pos]);
  if (abs(new_add) > abs(new_sub)) {
    return new_sub;
  }
  return new_add;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  cout << abs(solution(0, 0)) << endl;

  return 0;
}
