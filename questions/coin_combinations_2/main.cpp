#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int n, x;
vector<int> solutions(1E6 + 100, 0);
vector<int> coins;
const int mod = 1E9 + 7;

void solution() {
  solutions[0] = 1;
  for (auto k : coins) {
    for (int i = 1; i <= x; i++) {
      if (k <= i) {
        solutions[i] += solutions[i - k];
        solutions[i] %= mod;
      }
    }
  }
	cout << solutions[x] << endl;
}


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> x;
  coins.resize(n);
  for (auto &i : coins) {
    cin >> i;
  }
  sort(coins.begin(), coins.end());

  solution();

  return 0;
}
