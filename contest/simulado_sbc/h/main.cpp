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
  int n, k;
  cin >> n >> k;
  vector<int> N(n);

  map<int, vector<int>> mp;

  for (int i = 0; i < n; i++) {
    int value, color;
    cin >> value >> color;
    N[i] = color;
    mp[color].push_back(value);
  }
  for (auto &[i, j] : mp) {
    sort(j.rbegin(), j.rend());
  }

  int last = *mp[N[0]].rbegin();
  mp[N[0]].pop_back();
  N.pop_back();

  for (int i = 1; i < n; i++) {
    int temp = *mp[N[i]].rbegin();
    if (temp < last) {
      cout << "N" << endl;
      return 0;
    }
    last = temp;
    mp[N[i]].pop_back();
  }

  cout << "Y" << endl;
  return 0;

  // map<int, pair<vector<int>, vector<int>>> mp;
  // for (int i = 0; i < n; i++) {
  //   int x, c;
  //   cin >> x >> c;
  //   mp[c].first.push_back(x);
  //   mp[c].second.push_back(i);
  // }
  // vector<int> v(n);
  // for (auto &[_, p] : mp) {
  //   sort(p.first.begin(), p.first.end());
  //   for (int i = 0; i < p.first.size(); i++) {
  //     v[p.second[i]] = p.first[i];
  //   }
  // }
  // for (int i = 1; i < n; i++) {
  //   if (v[i - 1] > v[i]) {
  //     cout << "N" << endl;
  //     return 0;
  //   }
  // }
  // cout << "Y" << endl;
  // return 0;
}
