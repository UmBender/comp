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

vector<int> count(string &a, int begin, int end) {
  vector<int> counter(256, 0);
  for (int i = begin - 1; i < end; i++) {
    counter[a[i]]++;
  }
  return counter;
}

void print(vector<int> &arr) {
  for (int i = 'a'; i < 'z' + 1; i++) {
    cout << (char)(i) << " " << arr[i] << endl;
  }
}

void solution() {
  int n, q;
  cin >> n >> q;
  string a, b;
  cin >> a;
  cin >> b;

  vector<vector<int>> first(n + 1, vector<int>(26, 0));
  vector<vector<int>> second(n + 1, vector<int>(26, 0));

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < 26; j++) {
      first[i + 1][j] += first[i][j];
      second[i + 1][j] += second[i][j];
    }
    first[i + 1][a[i] - 'a']++;
    second[i + 1][b[i] - 'a']++;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    int diff = 0;

    for (int i = 0; i < 26; i++) {
      int word1 = first[r][i] - first[l - 1][i];
      int word2 = second[r][i] - second[l - 1][i];
      diff += abs(word1 - word2);
    }
    cout << diff / 2 << endl;
  }
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
