#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void solution() {
  string s;
  cin >> s;
  int value1 = s[0] - '0';
  int value2 = s[2] - '0';
  cout << value1 * value2;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
