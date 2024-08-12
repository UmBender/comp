#include <algorithm>
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

struct Sieve {
  vector<int32_t> lp;
  vector<int32_t> pr;

  Sieve() {}

  Sieve(int n) { setup(n); }

  void setup(int n) {
    lp.resize(n + 1);
    pr.clear();
    for (int i = 2; i <= n; i++) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= n; j++) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
          break;
        }
      }
    }
  }

  inline bool is_prime(int p) { return lp[p] == p; }

  inline int prime(int idx) { return pr[idx]; }
};

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

int bs(vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] == target) {
      return middle;
    }

    if (arr[middle] > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

struct DSU {
  vector<int> parents;
  vector<int> size;
  int sets;
  int max_size_set;

  DSU(int n) : parents(n), size(n, 1), sets(n), max_size_set(1) {
    for (int i = 0; i < n; i++)
      parents[i] = i;
  }

  int find(int x) {
    if (parents[x] == x) {
      return x;
    }
    int temp = this->find(parents[x]);
    parents[x] = temp;
    return temp;
  }

  bool unite(int a, int b) {
    int a_root = this->find(a);
    int b_root = this->find(b);

    if (a_root == b_root)
      return false;

    if (size[a_root] < size[b_root]) {
      swap(a_root, b_root);
    }

    size[a_root] += size[b_root];
    if (size[a_root] > max_size_set) {
      max_size_set = size[a_root];
    }
    parents[b_root] = a_root;
    --sets;
    return true;
  }

  inline bool same(int a, int b) { return this->find(a) == this->find(b); }
  inline int max_size() { return max_size_set; }
  inline int groups() { return sets; }
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;

  auto disjoint = DSU(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    disjoint.unite(a - 1, b - 1);
    cout << disjoint.groups() << ' ' << disjoint.max_size() << endl;
  }

  return 0;
}
