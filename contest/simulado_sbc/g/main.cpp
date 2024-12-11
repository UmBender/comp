#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

struct Sieve {
  vector<int32_t> lp;
  vector<int32_t> pr;

  Sieve() {}

  Sieve(int n) { setup(n); }

  void setup(int n) {
    lp.resize(n + 1);
    pr.clear();
    for (int i = 2; i <= n; i++) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= n; j++) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
          break;
        }
      }
    }
  }

  inline bool is_prime(int p) { return lp[p] == p; }

  inline int prime(int idx) { return pr[idx]; }
};

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

int bs(vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] == target) {
      return middle;
    }

    if (arr[middle] > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

vector<int> fib = {1, 1};
void fib_gen(int n) {
  while (*fib.rbegin() + *(fib.rbegin() + 1) <= n) {
    fib.push_back(*(fib.rbegin()) + *(fib.rbegin() + 1));
  }
}

vector<int> facts;

bool possible(int n) {
  if (n == 1) {
    return true;
  }
  for (int i = 2; i < fib.size(); i++) {
    facts.push_back(i - 1);
    if (n % fib[i] == 0) {
      if (possible(n / fib[i])) {
        return true;
      }
    }
    facts.pop_back();
  }
  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  fib_gen(n);
  if (possible(n)) {
    string ans;
    for (int i : facts) {
      ans += 'B';
      ans += string(i, 'A');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
