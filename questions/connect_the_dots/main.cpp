// #include <atcoder/all>
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
using ll = long long;
#define int ll

struct DSU {
  vector<int> sets;
  vector<int> sizes;
  int connected_components;
  DSU(int size)
      : sets(size + 1), sizes(size + 1, 1), connected_components(size) {
    for (int i = 0; i < sets.size(); i++) {
      sets[i] = i;
    }
  }

  int get_parent(int a) {

    if (sets[a] == a) {
      return a;
    }
    int parent = get_parent(sets[a]);
    sets[a] = parent;
    return parent;
  }

  bool is_same(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    return a == b;
  }

  bool join(int a, int b) {
		if(a == 0 || b == 0) {
			return false;
		}
    a = get_parent(a);
    b = get_parent(b);
    if (a == b) {
      return false;
    }
    if (sizes[a] < sizes[b]) {
      swap(a, b);
    }
    sets[b] = a;
    sizes[a] += sizes[b];
    connected_components--;
    return true;
  }
};

void solution() {
  int n, m;
  cin >> n >> m;

  DSU dsu(n);
  vector<tuple<int, int, int, int>> opt;
  stack<tuple<int, int, int>> s;

  for (int i = 0; i < m; i++) {
    int a, d, k;
    cin >> a >> d >> k;
      opt.push_back({a + d * k, a, d, k});
  }
  sort(opt.rbegin(), opt.rend());
  vector<vector<int>> solves(n + 1, vector<int>(11));
  for (auto [maxx, a, d, k] : opt) {
    int new_max = maxx;
    int i = a;
		dsu.join(i, maxx);
    while (i <= a + d * k) {
      dsu.join(i, maxx);
			for(int l = 1; l < 11; l++) 
				dsu.join(i, solves[i][l]);
      if (solves[i][d] == 0) {
        solves[i][d] = maxx;
      } else if (maxx > solves[i][d]) {
        solves[i][d] = maxx;
      } else {
        dsu.join(i, new_max);
        new_max = solves[i][d];
        break;
      }
      i += d;
    }
    if (new_max != maxx) {
      while (i >= a) {
        solves[i][d] = new_max;
				dsu.join(i, new_max);
        i -= d;
      }
    }
    dsu.join(a, new_max);
  }
  cout << dsu.connected_components << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
