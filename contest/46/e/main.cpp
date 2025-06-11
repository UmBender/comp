#include <atcoder/all>
#include <bits/stdc++.h>
#include <vector>

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
using ll = long long;
#define int ll
using mint = atcoder::modint;

vector<vector<char>> mat;
vector<vector<int>> path_sizes;

void solution() {
  int n;
  cin >> n;
  mat = vector<vector<char>>(n, vector<char>(n));
  path_sizes = vector<vector<int>>(n, vector<int>(n, MAX_INT));

  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  for(int i = 0 ; i < n; i++) {
    q.push({i,i});
    path_sizes[i][i] =0;
  }
  for(int i = 0; i < n;i++) {
    for(int j = 0; j < n; j++) {
      if(i == j || mat[i][j] == '-')
        continue;
      q.push({i,j});
      path_sizes[i][j] = 1;
    }
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < n; k++) {
      for (int l = 0; l < n; l++) {
        if (mat[k][i] != '-' && mat[j][l] != '-' && mat[k][i] == mat[j][l] &&
            path_sizes[k][l] == MAX_INT) {
          path_sizes[k][l] = path_sizes[i][j] + 2;
          q.push({k, l});
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val = path_sizes[i][j];
      cout << (val == MAX_INT ? -1 : val) << ' ';
    }
    cout << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
