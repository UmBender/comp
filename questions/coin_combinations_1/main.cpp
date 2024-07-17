#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int n, x;
vector<int> coins;
vector<int> solutions(1E6 + 100, 0);
const int mod = 1E9 + 7;

int test(int k) {
  if (solutions[k] == -1) {
    return -1;
  }
  if (solutions[k] != -1 && solutions[k] != 0) {
    return solutions[k];
  }

  int counter = 0;
  bool finded_solution = false;
  for (auto i : coins) {
    if (i > k) {
      break;
    }
    if (i == k) {
      counter++;
      counter %= mod;
      finded_solution = true;
    }
  }

  for (auto i : coins) {
    if (i >= k) {
      break;
    }
    int state_value = test(k - i);
    if (state_value != -1 && state_value != 0) {
      counter += state_value;
      counter %= mod;
      finded_solution = true;
    }
  }
  if (finded_solution) {
    solutions[k] = counter;
  }else{
		solutions[k] = -1;
	}

  return finded_solution ? counter : -1;
}

void solution() {
  int value = test(x);
  if (value != -1) {
    cout << value << endl;
    return;
  }
  cout << 0 << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> x;
  coins = vector<int>(n);
  for (auto &i : coins) {
    cin >> i;
  }

  sort(coins.begin(), coins.end());

  solution();

  return 0;
}
