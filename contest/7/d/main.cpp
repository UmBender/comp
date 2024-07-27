#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

int bsb(int n, int x, int a) {
  int left = 0;
  int right = min(n, x);
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (a * middle + a + middle <= n && a + middle + 1 <= x &&
        (a * (middle + 1) + 2 * a + 2 * middle > n || a + middle + 2 > x)) {
      return middle;
    }

    if (a * middle + a + middle > n || a + middle + 1 > x) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return 0;
}

int bsc(int n, int x, int a, int b) {
  int left = 0;
  int right = min(n, x);
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (a * middle + a * b + b * middle <= n && a + b + middle <= x &&
        (a * (middle + 1) + a * b + b * (middle + 1) > n ||
         a + middle + b + 1 > x)) {
      return middle;
    }

    if (a * middle + a * b + b * middle > n || a + b + middle > x) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return 0;
}

void solution() {
  int n, x;
  cin >> n >> x;
  /* int counter = 0; */
  /* for (int i = 1; i < n; i++) { */
  /*   for (int j = 1; j < n; j++) { */
  /*     for (int k = 1; k < n; k++) { */
  /*       if (i + j + k <= x && i * j + j * k + i * k <= n) { */
  /*         counter++; */
  /*       } else { */
  /*         break; */
  /*       } */
  /*     } */
  /*     if (i + j + 1 > x || i * j + i + j > n) { */
  /*       break; */
  /*     } */
  /*   } */
  /* } */
  int counter = 0;
  for (int i = 1; true; i++) {
    int max_b = bsb(n, x, i);
    for (int j = 1; true ; j++) {
      int max_c = bsc(n, x, i, j);
      counter += max_c;
      if (max_c == 0) {
        break;
      }
    }
    if (max_b == 0) {
      break;
    }
  }
  cout << counter << endl;
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
