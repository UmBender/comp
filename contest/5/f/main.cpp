#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void solution() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + 1 < c) {
    cout << -1 << endl;
    return;
  }else if(a + 1 > c) {
		cout << -1 << endl;
		return;
	} 
  int spaces = 1;
  int new_level_spaces = 0;
  int height = 0;
  while (a + b + c != 0) {
    while (spaces != 0) {
      if (a != 0) {
        a--;
        new_level_spaces += 2;
        spaces--;
      } else if (b != 0) {
        b--;
        new_level_spaces += 1;
        spaces--;
      } else if (c != 0) {
        c--;
        spaces--;
      } else {
        break;
      }
    }
    if (a + b + c == 0) {
      cout << height << endl;
    } else {
      spaces = new_level_spaces;
      new_level_spaces = 0;
      height++;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution();
  }

  return 0;
}
