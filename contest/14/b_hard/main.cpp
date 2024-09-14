#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)

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

int n;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

int bsu(vector<int> &arr, int target) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (m > 0 && arr[m] >= target && arr[m - 1] < target) {
      return arr[m];
    }
    if (m == arr.size() - 1 && arr[m] < target) {
      return n + 1;
    }
    if (m == 0) {
      if (arr[m] >= target) {
        return arr[m];
      } else {
        return arr[m + 1];
      }
    }
    if (arr[m] > target) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}
int bsl(vector<int> &arr, int target) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (m < arr.size() - 1 && arr[m] <= target && arr[m + 1] > target) {
      return arr[m];
    }
    if (m == arr.size() - 1) {
      if (arr[m] <= target) {
        return arr[m];
      } else {
        return arr[m - 1];
      }
    }
    if (m == 0 && arr[m] > target) {
      return 0;
    }
    if (arr[m] > target) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

void solution() {
  int m, q;
  cin >> n >> m >> q;
  vector<int> teacher_pos(m + 1, 0);
  int pos_root = ceil(sqrt(m));
  vector<pair<int, int>> sqrt_teacher(pos_root);
  vector<int> dq(q);
  for (int i{1}; i <= m; i++) {
    cin >> teacher_pos[i];
  }
  sort(teacher_pos.begin(), teacher_pos.end());
  for (auto &i : dq) {
    cin >> i;
  }
  for (auto i : dq) {
    int lower = bsl(teacher_pos, i);
    int upper = bsu(teacher_pos, i);
    if (lower == 0 && upper != i) {
      cout << upper - 1 << endl;
      continue;
    }
    if (upper == n + 1 && lower != i) {
      cout << n - lower << endl;
      continue;
    }

    if (upper == lower) {
      if (lower == i) {
        cout << 0 << endl;
      } else {
        if (lower < i) {
          cout << n - lower << endl;
        } else {
          cout << lower - 1 << endl;
        }
        continue;
      }
    }
    if (upper == i || lower == i) {
      cout << 0 << endl;
      continue;
    }

    cout << (upper - lower) / 2 << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
