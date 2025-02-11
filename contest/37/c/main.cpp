#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

int bs(int value, int target, vector<int> &arr) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;

    if (middle == 0) {
      if (arr[middle] - value >= target) {
        return middle;
      }
    }
    if (middle != 0 && arr[middle] - value >= target &&
        arr[middle - 1] - value < target) {
      return middle;
    }

    if (arr[middle] - value < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}

void solution() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }

  sort(b.begin(), b.end());

  if (n == 1) {
    cout << "YES" << endl;
    return;
  }

  int last = (int)(-1E18);
  for (int i = 0; i < a.size(); i++) {
    int pos = bs(a[i], last, b);
    if (pos != -1) {
      if (a[i] >= last) {
        last = min(b[pos] - a[i], a[i]);
      } else {
        last = b[pos] - a[i];
      }

    } else {
      if (a[i] >= last) {
        last = a[i];
      } else {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
