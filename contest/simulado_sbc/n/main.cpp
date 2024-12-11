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

struct BIT {
  vector<int> t;
  int n;

  BIT(int n) : t(n + 1), n(n) {}

  void add(int i, int val) {
    while (i <= n) {
      t[i] += val;
      i += i & -i;
    }
  }

  int query(int r) {
    int sum = 0;
    while (r > 0) {
      sum += t[r];
      r -= r & -r;
    }
    return sum;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int y, n;
  cin >> y >> n;
  vector<int> ans(n, 0);
  vector<int> x(y + 1);
  for (int i = 1; i <= y; i++) {
    cin >> x[i];
  }
  vector<vector<int>> starts(y + 1);
  vector<vector<int>> ends(y + 1);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    int a, p, f;
    cin >> a >> p >> f;
    pos[i] = p;
    if (x[a] >= p) {
      continue;
    }
    starts[a].push_back(i);
    ends[a + f].push_back(i);
  }
  BIT bit(100005);
  for (int i = 1; i <= y; i++) {
    bit.add(x[i], 1);
    for (int j : starts[i]) {
      ans[j] -= bit.query(100005) - bit.query(pos[j] - 1);
    }
    for (int j : ends[i]) {
      ans[j] += bit.query(100005) - bit.query(pos[j] - 1);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
