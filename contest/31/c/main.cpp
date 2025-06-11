#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl '\n'

#define MAX_INT ((int)1E18 + 1000)

void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)

void new_solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  int different = 1;
  int pos = 0;

  for (auto &i : a) {
    cin >> i;
    if (i != 1 && i != -1) {
      different = i;
    }
    if (different == 1) {
      pos++;
    }
  }

  vector<int> solution;
  if (different != 1) {
    pair<int, int> left, right;
    int acc = 0;
    for (int i = 0; i < pos; i++) {
      acc += a[i];
      if (acc < left.first) {
        left.first = acc;
      }
      if (acc > 0) {
        acc = 0;
      }
    }
    acc = 0;
    for (int i = 0; i < pos; i++) {
      acc += a[i];
      if (acc > left.second) {
        left.second = acc;
      }
      if (acc < 0) {
        acc = 0;
      }
    }

    acc = 0;
    for (int i = pos + 1; i < n; i++) {
      acc += a[i];
      if (acc < right.first) {
        right.first = acc;
      }
      if (acc > 0) {
        acc = 0;
      }
    }
    acc = 0;
    for (int i = pos + 1; i < n; i++) {
      acc += a[i];
      if (acc > right.second) {
        right.second = acc;
      }
      if (acc < 0) {
        acc = 0;
      }
    }

    pair<int, int> leftwith, rightwith;
    acc = 0;
    for (int i = pos - 1; i >= 0; i--) {
      acc += a[i];
      if (acc < leftwith.first) {
        leftwith.first = acc;
      }
    }
    acc = 0;
    for (int i = pos - 1; i >= 0; i--) {
      acc += a[i];
      if (acc > leftwith.second) {
        leftwith.second = acc;
      }
    }
    acc = 0;
    for (int i = pos + 1; i < n; i++) {
      acc += a[i];
      if (acc < rightwith.first) {
        rightwith.first = acc;
      }
    }
    acc = 0;
    for (int i = pos + 1; i < n; i++) {
      acc += a[i];
      if (acc > rightwith.second) {
        rightwith.second = acc;
      }
    }
    pair<int, int> without =
        make_pair(min(left.first, right.first), max(left.second, right.second));
    pair<int, int> with =
        make_pair(different + leftwith.first + rightwith.first,
                  different + leftwith.second + rightwith.second);

    if (with.first > without.first) {
      swap(with, without);
    }
    for (int i = with.first; i <= with.second; i++) {
      solution.push_back(i);
    }
    for (int i = max(with.second + 1, without.first); i <= without.second;
         i++) {
      solution.push_back(i);
    }

  } else {
    int minval = 0;
    int maxval = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) {
      acc += a[i];
      if (acc < minval) {
        minval = acc;
      }
      if (acc > 0) {
        acc = 0;
      }
    }
    acc = 0;
    for (int i = 0; i < n; i++) {
      acc += a[i];
      if (acc > maxval) {
        maxval = acc;
      }
      if (acc < 0) {
        acc = 0;
      }
    }
    for (int i = minval; i <= maxval; i++)
      solution.push_back(i);
  }
  cout << solution.size() << endl;
  for (int i = 0; i < solution.size(); i++) {
    cout << solution[i] << " \n"[i == solution.size() - 1];
  }
}
void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> dadif;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 1 && a[i] != -1) {
      dadif.push_back(make_pair(a[i], i));
    }
  }
  if (dadif.size()) {
    int left_min = 0;
    int left_max = 0;
    int right_min = 0;
    int right_max = 0;
    // left
    {
      vector<int> inverted(dadif[0].second);
      for (int i = 0; i < inverted.size(); i++) {
        inverted[i] = -a[i];
      }
      int min_value = 0;
      int actual_sum = 0;
      for (int i = 0; i < inverted.size(); i++) {
        actual_sum += inverted[i];
        if (actual_sum > min_value) {
          min_value = actual_sum;
        }
        if (actual_sum < 0) {
          actual_sum = 0;
        }
      }
      int max_value = 0;
      actual_sum = 0;
      for (int i = 0; i < inverted.size(); i++) {
        actual_sum += a[i];
        if (actual_sum > max_value) {
          max_value = actual_sum;
        }
        if (actual_sum < 0) {
          actual_sum = 0;
        }
      }
      min_value = -min_value;
      left_min = min_value;
      left_max = max_value;
    }

    // right
    {
      int min_value = 0;
      int max_value = 0;
      int actual_sum = 0;
      for (int i = dadif[0].second + 1; i < n; i++) {
        actual_sum += a[i];
        if (actual_sum < min_value) {
          min_value = actual_sum;
        }
        if (actual_sum > 0) {
          actual_sum = 0;
        }
      }
      actual_sum = 0;
      for (int i = dadif[0].second + 1; i < n; i++) {
        actual_sum += a[i];
        if (actual_sum > max_value) {
          max_value = actual_sum;
        }
        if (actual_sum < 0) {
          actual_sum = 0;
        }
      }
      right_min = min_value;
      right_max = max_value;
    }

    int max_left_apart = 0;
    int min_left_apart = 0;
    int min_right_apart = 0;
    int max_right_apart = 0;
    int acc = 0;

    for (int i = dadif[0].second - 1; i >= 0; i--) {
      acc += a[i];
      if (acc > max_left_apart) {
        max_left_apart = acc;
      }
      if (acc < min_left_apart) {
        min_left_apart = acc;
      }
    }
    acc = 0;
    for (int i = dadif[0].second + 1; i < n; i++) {
      acc += a[i];
      if (acc > max_left_apart) {
        max_left_apart = acc;
      }
      if (acc < min_left_apart) {
        min_left_apart = acc;
      }
    }
    int forone_min = min(left_min, right_min);
    int forone_max = max(left_max, right_max);
    int mvalue = dadif[0].first;
    int min_for_value = min_right_apart + min_left_apart + mvalue;
    int max_for_value = max_right_apart + max_left_apart + mvalue;

    vector<int> solve;
    if (forone_min < min_for_value) {
      for (int i = forone_min; i <= forone_max; i++) {
        solve.push_back(i);
      }
      for (int i = max(min_for_value, forone_max + 1); i <= max_for_value;
           i++) {
        solve.push_back(i);
      }
      cout << solve.size() << endl;
      for (auto i : solve) {
        cout << i << ' ';
      }
      cout << endl;
    } else {
      vector<int> solve;
      for (int i = min_for_value; i <= max_for_value; i++) {
        solve.push_back(i);
      }
      for (int i = max(max_for_value + 1, forone_min); i <= forone_max; i++) {
        solve.push_back(i);
      }
      cout << solve.size() << endl;
      for (auto i : solve) {
        cout << i << ' ';
      }
      cout << endl;
    }
  } else {
    int minimal = 0;
    int maximal = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum > maximal) {
        maximal = sum;
      }
      if (sum < 0) {
        sum = 0;
      }
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum < minimal) {
        minimal = sum;
      }
      if (sum > 0) {
        sum = 0;
      }
    }
    cout << (maximal - minimal) + 1 << endl;
    for (int i = minimal; i <= maximal; i++) {
      cout << i << ' ';
    }
    cout << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    new_solution();
  }

  return 0;
}
