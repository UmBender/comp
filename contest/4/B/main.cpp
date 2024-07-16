#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10
#define debugin cout << "ENTROU" << endl;

int bs(vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] == target && arr[middle + 1] != target) {
      return middle;
    }
    if (arr[middle] > target)
      right = middle - 1;
    else
      left = middle + 1;
  }
  return -1;
}

void print(vector<int> &arr) {
  for (int i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}
void solution() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(k);
  for (auto &i : arr) {
    cin >> i;
  }

  sort(arr.begin(), arr.end());

  int one = bs(arr, 1);
  int biggest = arr[arr.size() - 1];
  arr.pop_back();

  int op_counter = 0;
  int value = biggest;

  if ((value + one + 1) >= n) {
    cout << n - value << endl;
    return;
  }
  int begin_pos = one + 1;

  value += one + 1;
  op_counter += one + 1;
  for (int i = begin_pos; i < arr.size() ; i++) {
    if (value + arr[i] == n) {
      op_counter += 2 * arr[i] - 1;
      cout << op_counter << endl;
      return;
    }
    if (value + arr[i] > n) {
      int needed = n - value;
      op_counter += 2 * needed;
      cout << op_counter << endl;
      return;
    }

    value += arr[i];
    op_counter += 2 * arr[i] - 1;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution();
  }

  return 0;
}
