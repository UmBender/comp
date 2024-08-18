#include <bits/stdc++.h>
#include <iterator>

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

class DSU {
private:
  vector<int> parents;
  vector<int> sizes;
  int n_sets;
  int max_size_set;

public:
  DSU(int n) : parents(n), sizes(n, 1), n_sets(n), max_size_set(1) {
    for (int i = 0; i < n; ++i)
      parents[i] = i;
  }

  int find(int n) {
    if (parents[n] == n) {
      return n;
    }
    int temp = this->find(parents[n]);
    parents[n] = temp;
    return temp;
  }
  bool join(int a, int b) {
    int a_root = this->find(a);
    int b_root = this->find(b);
    if (a_root == b_root) {
      return false;
    }

    if (sizes[a_root] < sizes[b_root]) {
      swap(a_root, b_root);
    }
    sizes[a_root] += sizes[b_root];
    parents[b_root] = a_root;
    return true;
  }

  inline bool same_set(int a, int b) { return this->find(a) == this->find(b); }
};
bool is_palindrome(string a, string b) {
  if (a.size() == 1) {
    a = "0" + a;
  }
  if (b.size() == 1) {
    b = "0" + b;
  }
  return a[1] == b[0] && a[0] == b[1];
}

void solution() {
  string s;
  cin >> s;
  int t;
  cin >> t;
  string sh, sm;
  sh.push_back(s[0]);
  sh.push_back(s[1]);
  sm.push_back(s[3]);
  sm.push_back(s[4]);
  int h = stoi(sh);
  int m = stoi(sm);
  int begin_h = h;
  int begin_m = m;
  int nh = t / 60;
  int nm = t % 60;
  int counter = is_palindrome(to_string(begin_h), to_string(begin_m));

  m += nm;
  if (m > 59) {
    h += 1;
    m %= 60;
  }
  h += nh;
  if (h > 23) {
    h %= 24;
  }
  cerr << "old: " << begin_h << ' ' << begin_m << endl;
  cerr << "new: " << h << ' ' << m << endl;

  while (1) {
    counter += is_palindrome(to_string(h), to_string(m));
    m += nm;
    if (m > 59) {
      h += 1;
      m %= 60;
    }
    h += nh;
    if (h > 23) {
      h %= 24;
    }
    cerr << h << ' ' << m << endl;
    if (h == begin_h && m == begin_m == m) {
      break;
    }
  }
  cout << counter << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }

  return 0;
}
