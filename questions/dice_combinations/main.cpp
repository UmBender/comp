#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
const int mod = 1e9 + 7;

vector<int> sol(10E6 + 100, -1);
int test(int n) {
  if (sol[n] == -1) {

    int counter = 0;
    if (n <= 6) {
      counter++;
    }
    for (int i = 1; i < n && i <= 6; i++) {
      counter += test(n - i);
    }
    sol[n] = counter % mod;
  }
  return sol[n];
}
void solution() {
  int n;
  cin >> n;
  sol[1] = 1;

  cout << test(n) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  solution();

  return 0;
}
