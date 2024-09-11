#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define int ll
#define endl (char)10

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

int n, m;
vector<vector<int>> adj;
vector<vector<int>> path;
vector<vector<bool>> state;
queue<pair<int, int>> a;
queue<pair<int, int>> monsters;
bool won = false;
int won_i = -1, won_j = -1;
int init_a_i = -1, init_a_j = -1;

bool woned(int i, int j) {
  if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
    won_i = i;
    won_j = j;

    return true;
  }
  return false;
}

void build_graph(vector<string> &input) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (input[i][j] == '#') {
        continue;
      }
      if (i > 0 && input[i - 1][j] != '#') {
        adj[i * m + j].push_back((i - 1) * m + j);
      }
      if (j > 0 && input[i][j - 1] != '#') {
        adj[i * m + j].push_back(i * m + j - 1);
      }
      if (i < n - 1 && input[i + 1][j] != '#') {
        adj[i * m + j].push_back((i + 1) * m + j);
      }
      if (j < m - 1 && input[i][j + 1] != '#') {
        adj[i * m + j].push_back(i * m + j + 1);
      }
      if (input[i][j] == 'M') {
        monsters.push(make_pair(i, j));
        state[i][j] = false;
      }
      if (input[i][j] == 'A') {
        a.push(make_pair(i, j));
        init_a_i = i;
        init_a_j = j;
        if (woned(i, j)) {
          won = true;
        }
      }
    }
  }
}
void bfs() {
  int n_a = a.size();
  int n_m = monsters.size();
  queue<pair<int, int>> h_a;
  queue<pair<int, int>> h_m;
  int a_a = 0;
  int m_m = 0;
  while (!won && !a.empty()) {
    while (!monsters.empty()) {
      pair<int, int> now_m = monsters.front();
      monsters.pop();
      for (int k : adj[now_m.first * m + now_m.second]) {
        if (state[k / m][k % m]) {
          state[k / m][k % m] = false;
          m_m++;
          h_m.push(make_pair(k / m, k % m));
        }
      }
    }
    n_m = m_m;
    m_m = 0;
    swap(h_m, monsters);

    while (!a.empty()) {
      pair<int, int> now_a = a.front();
      a.pop();
      for (int k : adj[now_a.first * m + now_a.second]) {
        if (woned(k / m, k % m) && state[k / m][k % m]) {
          won = true;
        }
        if (state[k / m][k % m]) {
          if (k / m == now_a.first) {
            if (k % m > now_a.second) {
              path[now_a.first][k % m] = 'L';
            } else {
              path[now_a.first][k % m] = 'R';
            }

          } else {
            if (k / m > now_a.first) {
              path[k / m][now_a.second] = 'U';
            } else {
              path[k / m][now_a.second] = 'D';
            }
          }

          a_a++;
          h_a.push(make_pair(k / m, k % m));
          if (won) {
            return;
          }
        }
        state[k / m][k % m] = false;
      }
    }
    n_a = a_a;
    a_a = 0;
    swap(h_a, a);
  }
}

void show_adj() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << "I: " << i << " J: " << j << endl;
      for (auto k : adj[i * m + j]) {
        cout << "     i: " << k / m << " j: " << k % m << endl;
      }
    }
  }
}

void solution() {
  cin >> n >> m;
  adj.resize(n * m);
  path.resize(n, vector<int>(m, 0));
  state.resize(n, vector<bool>(m, true));
  vector<string> map(n);
  for (auto &i : map) {
    cin >> i;
  }
  build_graph(map);
  bfs();
  if (won) {
    vector<int> da_path;
    while (!(won_i == init_a_i && won_j == init_a_j)) {
      switch (path[won_i][won_j]) {
      case 'D':
        da_path.push_back('U');
        won_i++;
        break;
      case 'U':
        da_path.push_back('D');
        won_i--;

        break;
      case 'L':
        da_path.push_back('R');
        won_j--;

        break;
      default:
      case 'R':
        da_path.push_back('L');
        won_j++;

        break;
      }
    }
    reverse(da_path.begin(), da_path.end());
    cout << "YES" << endl << da_path.size() << endl;
    for (auto i : da_path) {
      cout << (char)i;
    }
    cout << endl;

  } else {
    cout << "NO" << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
