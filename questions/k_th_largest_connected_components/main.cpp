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

struct DSU {
  vector<int> parents;
  vector<int> sizes;
  vector<vector<int>> joins;
  DSU(int n) : parents(n + 1), sizes(n + 1, 1), joins(n + 1) {
    iota(parents.begin(), parents.end(), 0);
    for (int i = 0; i < n + 1; i++)
      joins[i] = {i};
  }

  int get_parent(int i) {
    if (i == parents[i]) {
      return i;
    }
    int parent = get_parent(parents[i]);

    parents[i] = parent;
    return parent;
  }
  inline bool connected(int i, int j) { return get_parent(i) == get_parent(j); }

  int get_greatest(int i, int k) {
    int parent = get_parent(i);

    if (joins[parent].size() < k) {
      return -1;
    }
    return joins[parent][k - 1];
  }

  bool join(int i, int j) {
    int parenti = get_parent(i);
    int parentj = get_parent(j);
    if (parenti == parentj) {
      return false;
    }
    if (sizes[parenti] < sizes[parentj]) {
      swap(parenti, parentj);
    }
    parents[parentj] = parenti;
    sizes[parenti] += sizes[parentj];
    for (auto i : joins[parentj]) {
      joins[parenti].push_back(i);
    }
    sort(joins[parenti].rbegin(), joins[parenti].rend());
    while (joins[parenti].size() > 10) {
      joins[parenti].pop_back();
    }
    return true;
  }
};
void solution() {
  int n, q;
  cin >> n >> q;
  auto dsu = DSU(n + 1);

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      dsu.join(u, v);
    } else {
      int v, k;
      cin >> v >> k;
      cout << dsu.get_greatest(v, k) << endl;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solution();

  return 0;
}
