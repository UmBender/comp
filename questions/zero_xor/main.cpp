#include <atcoder/all>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define endl '\n'
using ll = long long;
#define int ll

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> m;
  for (int &i : a) {
    cin >> i;
    m[i] = i;
  }
  int rest = 0;
  for (int i : a) {
    rest ^= i;
  }
  if (a.size() & 1) {
    cout << "Win" << endl;
    return;
  }
  if (m.count(rest)) {
    cout << "Win" << endl;
    return;
  }
  cout << "Lose" << endl;
  return;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solution();

  return 0;
}
