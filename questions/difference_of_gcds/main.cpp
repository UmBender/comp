#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

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

void solution() {
  int n, l, r;
  cin >> n >> l >> r;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    int k = l / i;
    k *= i;
    if (k != l) {
      k += i;
    }
    if (k > r) {
      cout << "NO" << endl;
      return;
    }
    arr[i] = k;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
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
