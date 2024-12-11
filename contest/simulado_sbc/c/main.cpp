#include <bits/stdc++.h>
#include <iostream>

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
  int b, l;
  cin >> b >> l;
  vector<int> d(l);
  for (auto &i : d) {
    cin >> i;
  }
  reverse(d.begin(), d.end());

  int sum = 0;
  for (int i = 0; i < l; i++) {
    sum += (i & 1) ? -d[i] : d[i];
  }
  sum = sum % (b + 1);

  if (sum < 0) {
    sum += b + 1;
  }

  if (sum == 0) {
    cout << "0 0" << endl;
    return 0;
  }
  if ((l & 1) == 0) {
    sum = b + 1 - sum;
  }
  cerr << sum << endl;
  reverse(d.begin(), d.end());
  for (int i = 0; i < l; i++) {
    if (d[i] >= sum) {
      cout << i + 1 << ' ' << d[i] - sum << endl;
      return 0;
    }
    sum = b + 1 - sum;
  }

  cout << "-1 -1" << endl;

  return 0;
}
