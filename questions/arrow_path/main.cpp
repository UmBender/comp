#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
#define makeconst(val) []() { return value; }
using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  string arrow[2];
  for (int i = 0; i < 2; i++) {
    cin >> arrow[i];
  }
  vector<vector<bool>> acessed(2, vector<bool>(n));
  queue<pair<int, int>> actual_cell;
  actual_cell.push({0, 0});
  while (!actual_cell.empty()) {
    auto [x, y] = actual_cell.front();
    actual_cell.pop();
    if (x > 0) {
      pair<int, int> new_cell = {x - 1, y};
      if (arrow[new_cell.second][new_cell.first] == '>') {
        new_cell.first++;
      } else {
        new_cell.first--;
      }
      if (new_cell.first >= 0 && new_cell.first < n &&
          !acessed[new_cell.second][new_cell.first]) {
        actual_cell.push(new_cell);
	acessed[new_cell.second][new_cell.first] = true;
      }
      if (new_cell.first == n - 1 && new_cell.second == 1) {
        cout << "YES" << endl;
        return;
      }
    }
    if (y > 0) {
      pair<int, int> new_cell = {x, y - 1};
      if (arrow[new_cell.second][new_cell.first] == '>') {
        new_cell.first++;
      } else {
        new_cell.first--;
      }
      if (new_cell.first >= 0 && new_cell.first < n &&
          !acessed[new_cell.second][new_cell.first]) {
        actual_cell.push(new_cell);
	acessed[new_cell.second][new_cell.first] = true;
      }
      if (new_cell.first == n - 1 && new_cell.second == 1) {
        cout << "YES" << endl;
        return;
      }
    }
    if (x < n - 1) {
      pair<int, int> new_cell = {x + 1, y};
      if (arrow[new_cell.second][new_cell.first] == '>') {
        new_cell.first++;
      } else {
        new_cell.first--;
      }
      if (new_cell.first >= 0 && new_cell.first < n &&
          !acessed[new_cell.second][new_cell.first]) {
        actual_cell.push(new_cell);
	acessed[new_cell.second][new_cell.first] = true;
      }
      if (new_cell.first == n - 1 && new_cell.second == 1) {
        cout << "YES" << endl;
        return;
      }
    }
    if (y < 1) {
      pair<int, int> new_cell = {x, y + 1};
      if (arrow[new_cell.second][new_cell.first] == '>') {
        new_cell.first++;
      } else {
        new_cell.first--;
      }
      if (new_cell.first >= 0 && new_cell.first < n &&
          !acessed[new_cell.second][new_cell.first]) {
        actual_cell.push(new_cell);
	acessed[new_cell.second][new_cell.first] = true;
      }
      if (new_cell.first == n - 1 && new_cell.second == 1) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
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
