#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;

  int pa = (((1 + n) * n) / 2);

  if (pa % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }

	cout << "YES" << endl;

  if (n % 2 == 0) {
    vector<int> primeiro;
    for (int i = 1; i <= n / 2; i += 2) {
      primeiro.push_back(i);
    }
    for (int i = n; i > n / 2; i -= 2) {
      primeiro.push_back(i);
    }
    vector<int> segundo;
    for (int i = 2; i <= n / 2; i += 2) {
      segundo.push_back(i);
    }
    for (int i = n - 1; i > n / 2; i -= 2) {
      segundo.push_back(i);
    }
    sort(primeiro.begin(), primeiro.end());
    sort(segundo.begin(), segundo.end());

    cout << primeiro.size() << endl;
    for (auto i : primeiro) {
      cout << i << " ";
    }
    cout << endl;

    cout << segundo.size() << endl;
    for (auto i : segundo) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    vector<int> primeiro;
    for (int i = 2; i < n / 2; i += 2) {
      primeiro.push_back(i);
    }
    for (int i = n; i > n / 2; i -= 2) {
      primeiro.push_back(i);
    }
    vector<int> segundo;
    for (int i = 3; i <= n / 2; i += 2) {
      segundo.push_back(i);
    }
    for (int i = n - 1; i > n / 2; i -= 2) {
      segundo.push_back(i);
    }
    segundo.push_back(1);
    sort(primeiro.begin(), primeiro.end());
    sort(segundo.begin(), segundo.end());

    cout << primeiro.size() << endl;
    for (auto i : primeiro) {
      cout << i << " ";
    }
    cout << endl;

    cout << segundo.size() << endl;
    for (auto i : segundo) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
