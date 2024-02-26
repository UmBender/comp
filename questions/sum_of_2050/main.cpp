#include <bits/stdc++.h>
#include <vector>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n';

int32_t main() {
  int T;
  cin >> T;
  vector<int> numbers(T);
  for (int k = 0; k < T; k++) {
    int a;
    cin >> a;
    numbers[k] = a;
  }
  for (int i = 0; i < T; i++) {
    if (numbers[i] % 2050 != 0) {
      cout << "-1" << '\n';
      continue;
    }
    int puts = numbers[i] / 2050;
    int sum = 0;
    while (puts > 0) {
      sum += puts % 10;
      puts /= 10;
    }
    cout << sum << endl;
  }

  return 0;
}
