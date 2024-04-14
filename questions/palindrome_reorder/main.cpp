#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  string palavra;
  cin >> palavra;
  vector<int> elements(256);
  int even_pos = -1;
  for (auto i : palavra) {
    elements[i]++;
  }
  int even = 0;
  for (int i = 'A'; i <= 'Z'; i++) {
    if ((elements[i] % 2) == 1) {
      even++;
      even_pos = i;
    }
  }
  if ((palavra.size() % 2) == 1) {
    if (even != 1) {
      cout << "NO SOLUTION" << endl;
      return 0;
    }
    elements[even_pos]--;
    for (int i = 'A'; i <= 'Z'; i++) {
      for (int j = 0; j < elements[i] / 2; j++) {
        cout << (char)i;
      }
    }
    cout << (char)even_pos;
    for (int i = 'Z'; i >= 'A'; i--) {
      for (int j = 0; j < elements[i] / 2; j++) {
        cout << (char)i;
      }
    }
    cout << endl;
    return 0;
  }
  if ((palavra.size() & 0b1) == 0) {
    if (even != 0) {
      cout << "NO SOLUTION" << endl;
      return 0;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
      for (int j = 0; j < elements[i] / 2; j++) {
        cout << (char)i;
      }
    }
    for (int i = 'Z'; i >= 'A'; i--) {
      for (int j = 0; j < elements[i] / 2; j++) {
        cout << (char)i;
      }
    }
    cout << endl;
    return 0;
  }

  return 0;
}
