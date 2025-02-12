#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int tx, ty;
  int bx = 0, by = 0;
  cin >> tx >> ty;
  if(tx < 0 && ty < 0) {
    cout << abs(tx) + abs(ty) << endl;
    return;
  }
  if(tx <0 ) {
    cout << max(abs(tx), abs(ty)) << endl;
    return;
  }
  if(ty < 0) {
    cout << max(abs(tx), abs(ty)) << endl;
    return;
  }
  cout << abs(tx) + abs(ty) << endl;
  




}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
