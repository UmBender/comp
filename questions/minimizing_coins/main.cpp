#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

vector<int> sol(10E6 + 100);
vector<int> coins;

int test(int n) {
  if (sol[n] == -1) {
    return -1;
  }
  if (sol[n] != 0) {
    return sol[n];
  }

  int minimal = INT_MAX; 
	bool founded = false;
	
  for (auto i : coins) {
    if (i > n) {
      break;
    }
    int tested = test(n - i);

    if (tested != -1) {
			founded = true;
      minimal = min(minimal, tested);
    }
  }
  if (!founded) {
    sol[n] = -1;
		return -1;
  } 
	sol[n] = minimal + 1;
  return minimal + 1;
}

void solution() {
  int n, x;
  cin >> n >> x;
  coins = vector<int>(n);
  for (auto &i : coins) {
    cin >> i;
    sol[i] = 1;
  }
  sort(coins.begin(), coins.end());
  int stats = test(x);
  if (stats == -1) {
    cout << -1 << endl;
    return;
  }
  cout << stats << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  solution();
  return 0;
}
