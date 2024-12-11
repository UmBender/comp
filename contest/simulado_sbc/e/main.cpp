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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int dir = -1;
  int stop = 0;
  queue<int> v[2];
  for (int i = 0; i < n; i++) {
    int t, d;
    cin >> t >> d;
    v[d].push(t);
  }
  while (!(v[0].empty() && v[1].empty())) {
    if (dir == -1) {
      if (v[1].empty()) {
        dir = 0;
        stop = max(stop, v[dir].front()) + 10;
        v[dir].pop();
        continue;
      }
      if (v[0].empty()) {
        dir = 1;
        stop = max(stop, v[dir].front()) + 10;
        v[dir].pop();
        continue;
      }
      if (v[1].front() > v[0].front()) {
        dir = 0;
        stop = max(stop, v[0].front()) + 10;

        v[0].pop();
      } else {
        dir = 1;
        stop = max(stop, v[1].front()) + 10;
        v[1].pop();
      }
      continue;
    }
    if (v[dir].empty()) {
      if (v[dir ^ 1].front() < stop) {
        stop += 10;
      } else {
        stop = v[dir ^ 1].front() + 10;
      }
      dir = dir ^ 1;
      v[dir].pop();
      continue;
    }
    if (v[dir].front() < stop) {
      stop = v[dir].front() + 10;
      v[dir].pop();
    } else {
      dir = -1;
    }
  }
  cout << stop << endl;

  return 0;
}
