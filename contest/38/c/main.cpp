#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  vector<int> parts;
  vector<int> ones_last;
  vector<int> ones_actual;
  int first = n % 10;
  n /= 10;
  while (n) {
    parts.push_back(n % 10);
    n /= 10;
  }
  int minn;
  int actual = first;
  int counter = 0;
  while (actual != 7) {
    actual += 9;
    ones_last.push_back(actual / 10);
    actual %= 10;
    counter++;
  }

  minn = counter;
  for (int i : parts) {
    int by_nine = 0;
    int value = i;
    while (value != 7 && by_nine < ones_last.size()) {
      value += 9;
      value += ones_last[by_nine];
      ones_actual.push_back(value / 10);
      value %= 10;
      by_nine++;
    }
    int by_ones = 0;
    value = i;
    while (value != 7 && by_ones < ones_last.size()) {
      value += ones_last[by_ones];
      value %= 10;
      by_ones++;
    }
    minn = min(minn, min(by_ones, by_nine));
    ones_last.clear();
    swap(ones_last, ones_actual);
  }
  int by_nine = 0;
  int value = 0;
  while (value != 7 && by_nine < ones_last.size()) {
    value += 9;
    value += ones_last[by_nine];
    ones_actual.push_back(value / 10);
    value %= 10;
    by_nine++;
  }
  int by_ones = 0;
  value = 0;
  while (value != 7 && by_ones < ones_last.size()) {
    value += ones_last[by_ones];
    value %= 10;
    by_ones++;
  }

  minn = min(minn, min(by_ones, by_nine));
  ones_last.clear();
  swap(ones_last, ones_actual);

  cout << minn << endl;
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
