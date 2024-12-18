#include <bits/stdc++.h>
#include <numeric>

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

struct DSU {
  vector<int> parent;
  vector<int> size;
  int _size;
  DSU(int n) : parent(n), size(n, 1), _size(n) {
    iota(parent.begin(), parent.end(), 0);
  }

  int get_parent(int i) {
    if (parent[i] == i)
      return i;

    parent[i] = get_parent(parent[i]);
    return parent[i];
  }
  bool is_connected(int i, int j) { return get_parent(i) == get_parent(j); }
  void join(int i, int j) {
    i = get_parent(i);
    j = get_parent(j);
    if (i == j)
      return;

    if (size[i] < size[j])
      swap(i, j);

    size[i] += size[j];
    parent[j] = i;
  }
  int get_size(int i) {
    i = get_parent(i);
    return size[i];
  }
};
void solution() {
  int n, q;
  cin >> n >> q;
  map<char, vector<vector<int>>> block;
  map<char, vector<DSU>> joined;
  vector<char> ords = {'x', 'y', 'z'};
  int counter = 0;
  for (auto i : ords) {
    block[i] = vector<vector<int>>(n, vector<int>(n));
    joined[i] = vector<DSU>(n, DSU(n));
  }
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    block['x'][y][z]++;
    block['y'][x][z]++;
    block['z'][x][y]++;
    if (block['x'][y][z] == n) {
      counter++;
    }
    if (block['y'][x][z] == n) {
      counter++;
    }
    if (block['z'][x][y] == n) {
      counter++;
    }
    cout << counter << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();
  return 0;
}
