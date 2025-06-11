#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

int bs(int sum, int target, int upper_bound) {
  int left = 0;
  int right = upper_bound - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (middle * sum <= target && (middle + 1) * sum > target) {
      return middle;
    }

    if (middle * sum > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

void solution() {
  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c;
  int t = bs(sum, n, 10E9 + 100);
  if (t * sum == n) {
    cout << t * 3 << endl;
    return;
  }
  if (t * sum + a >= n) {
    cout << t * 3 + 1 << endl;
    return;
  }
  if (t * sum + a + b >= n) {
    cout << t * 3 + 2 << endl;
    return;
  }
  if (t * sum + a + b + c >= n) {
    cout << t * 3 + 3 << endl;
    return;
  }
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
