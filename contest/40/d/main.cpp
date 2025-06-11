#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

int upper_bound(int target, int begin, vector<int> &arr) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (middle == 0) {
      if (arr[middle] >= target) {
        return middle;
      }
    } else if (arr[middle] >= target && arr[middle - 1] < target) {
      return middle;
    }
    if (arr[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}

int lower_bound(int target, int begin, vector<int> &arr) {
  int left = begin;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (middle == arr.size() - 1) {
      if (arr[middle] <= target) {
        return middle;
      }
    } else if (arr[middle] <= target && arr[middle + 1] > target) {
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

void solution() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int sum = reduce(a.begin(), a.end(), 0LL);
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (sum - x - a[i] < a[i + 1]) {
      continue;
    }
    if (sum - y - a[i] > a.back()) {
      continue;
    }

    int jx = lower_bound(sum - x - a[i], i + 1, a);
    int jy = upper_bound(sum - y - a[i], i + 1, a);
    jy = max(jy, i+1);


    if (jx >= jy)
      ans += (jx - jy) + 1;
  }
  cout << ans << endl;
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
