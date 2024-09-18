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

int bsu(vector<int> &arr, int target) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int middle = l + (r - l) / 2;
    if (middle == arr.size() - 1) {
      if (arr[middle] <= target) {
        return middle;
      } else {
        return middle - 1;
      }
    }
    if (arr[middle] <= target && arr[middle + 1] > target) {
      return middle;
    }

    if (arr[middle] <= target) {
      l = middle + 1;
    } else {
      r = middle - 1;
    }
  }
  return -1;
}
int bsl(vector<int> &arr, int target) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int middle = l + (r - l) / 2;
    if (middle == 0) {
      if (arr[middle] >= target) {
        return middle;
      } else {
        return middle + 1;
      }
    }
    if (arr[middle] >= target && arr[middle - 1] < target) {
      return middle;
    }
    if (arr[middle] < target) {
      l = middle + 1;
    } else {
      r = middle - 1;
    }
  }
  return -1;
}

void solution() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> p(n);
  for (auto &i : x) {
    cin >> i;
  }
  for (auto &i : p) {
    cin >> i;
  }
  vector<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + p[i - 1];
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    int lpos = bsl(x, l);
    int rpos = bsu(x, r);

    if (l == r && lpos != rpos) {
      cout << 0 << endl;
      continue;
    }

    cout << pref[rpos + 1] - pref[lpos] << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
