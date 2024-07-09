#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

int max(int i, int j) {
  if (i > j) {
    return i;
  }
  return j;
}

void teste() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;

  int sum_a = 0;
  int sum_b = 0;
  int pos_disputed = 0;
  int neg_disputed = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (a[i] == 1) {
        sum_a++;
      }
      if (b[i] == 1) {
        sum_b++;
      }
    } else {
      if (a[i] == -1) {
        neg_disputed++;
      }
      if (a[i] == 1) {
        pos_disputed++;
      }
    }
  }
  if (pos_disputed - neg_disputed == 1) {
    if (max(sum_a, sum_b) == 0) {
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
    }
    return;
  }
  if (pos_disputed - neg_disputed > 1) {
    cout << "1" << endl;
    return;
  }
  if (pos_disputed - neg_disputed == 0) {
    if (pos_disputed != 0) {
      if (sum_a >= 1 && sum_b >= 1) {
        cout << "1" << endl;
        return;
      }
      if (sum_a >= 2 && sum_b == 0) {
        cout << "1" << endl;
        return;
      }
      if (sum_b >= 2 && sum_a == 0) {
        cout << "1" << endl;
        return;
      }
      cout << "0" << endl;
    } else {
      if (sum_a == 0 || sum_b == 0) {
        cout << "0" << endl;
      } else {
        cout << "1" << endl;
      }
      return;
    }
  }
  if (pos_disputed - neg_disputed < 0) {
    int diff = neg_disputed - pos_disputed;
    if (diff > sum_a + sum_b) {
			cout << "-1" << endl;
			return;
    }
		if(diff == sum_a + sum_b) {
			cout << "0" << endl;
			return;
		}
		if(sum_a == 0) {
			cout << "0" << endl;
			return;
		}
		if(sum_b == 0) {
			cout << "0" << endl;
			return;
		}

		cout << "1" << endl;
		return;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    teste();
  }

  return 0;
}
