#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;
#define int ll
#define endl (char)10
#define mod ((int)1E9 + 7)

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
int test(int a, int b) {
	if (b == 0) {
		return 1;
	}
  if (b == 1) {
    return a;
  }

  int caps = test(a, b / 2);
  caps *= caps;
  caps %= mod;
  if (b % 2 == 1) {
    return caps * a % mod;
  }
  return caps;
}

void solution() {
  int a, b;
  cin >> a >> b;
  cout << test(a, b) % ((int)1E9 + 7) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    solution();
  }

  return 0;
}
