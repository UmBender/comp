#include <bits/stdc++.h>
#include <utility>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

void solution() {
  int n, m;
  cin >> n >> m;
  vector<pair<vector<int>, int>> cows(n, make_pair(vector<int>(m), 0));
  for (int i = 0; i < cows.size(); i++) {
    for (int j = 0; j < cows[i].first.size(); j++) {
      cin >> cows[i].first[j];
    }
    cows[i].second = i + 1;
    sort(cows[i].first.begin(), cows[i].first.end());
  }

  sort(cows.begin(), cows.end());
  const int columns = cows.front().first.size();
  const int lines = cows.size();

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < lines; j++) {
      if (cows[j].first[i] != j + i * lines) {
        cout << -1 << endl;
        return;
      }
    }
  }
  for(int i = 0; i < lines; i++) {
    cout << cows[i].second << " \n"[i == lines-1];
  }
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
