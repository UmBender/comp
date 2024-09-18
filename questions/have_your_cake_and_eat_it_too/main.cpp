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

int bs(vector<int> &arr, int begin, int target) {
  int l = begin + 1, r = arr.size() - 1;
  while (l <= r) {
    int middle = l + (r - l) / 2;
    if (arr[middle] - arr[begin] >= target &&
        arr[middle - 1] - arr[begin] < target) {
      // cerr << "FIRST: " << arr[middle] - arr[begin] << endl;
      // cerr << "SECOND: " << arr[middle - 1] - arr[begin] << endl;
      return middle;
    }
    if (arr[middle] - arr[begin] < target) {
      l = middle + 1;
    } else {
      r = middle - 1;
    }
  }
  return -1;
}

vector<pair<char, pair<int, int>>> result(vector<int> &suma, vector<int> &sumb,
                                          vector<int> &sumc, int target,
                                          vector<char> order) {
  int end_a = bs(suma, 0, target);
  if (end_a == -1) {
    return vector<pair<char, pair<int, int>>>(0);
  }

  int end_b = bs(sumb, end_a, target);
  if (end_b == -1) {
    return vector<pair<char, pair<int, int>>>(0);
  }

  // cerr << order[0] << " VAL: " << suma[end_a] - suma[0] << endl;
  // cerr << order[1] << " VAL: " << sumb[end_b] - sumb[end_a] << endl;
  // cerr << order[2] << " VAL: " << sumc[sumc.size() - 1] - sumc[end_b] <<
  // endl;

  if (sumc[sumc.size() - 1] - sumc[end_b] >= target) {
    vector<pair<char, pair<int, int>>> caps;
    caps.push_back(make_pair(order[0], make_pair(1, end_a)));
    caps.push_back(make_pair(order[1], make_pair(end_a + 1, end_b)));
    caps.push_back(make_pair(order[2], make_pair(end_b + 1, sumc.size() - 1)));
    return caps;
  }
  // cout << "HERE" << endl;
  return vector<pair<char, pair<int, int>>>(0);
}

void solution() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  int sum_a = 0, sum_b = 0, sum_c = 0;
  int tot = 0;
  for (auto &i : a) {
    cin >> i;
    tot += i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  for (auto &i : c) {
    cin >> i;
  }

  int ceil_tot = ceil((float)tot / 3.0);
  // cerr << "THIS TOT: " << ceil_tot << endl;
  vector<int> pref_a(n + 1), pref_b(n + 1), pref_c(n + 1);
  for (int i = 1; i <= n; i++) {
    pref_a[i] = a[i - 1] + pref_a[i - 1];
    pref_b[i] = b[i - 1] + pref_b[i - 1];
    pref_c[i] = c[i - 1] + pref_c[i - 1];
  }

  vector<pair<char, pair<int, int>>> results;
  results = result(pref_a, pref_b, pref_c, ceil_tot, {'a', 'b', 'c'});
  if (results.size() != 0) {
    sort(results.begin(), results.end());
    for (auto &i : results) {
      cout << i.second.first << ' ' << i.second.second << ' ';
    }
    cout << endl;
    return;
  }

  results = result(pref_a, pref_c, pref_b, ceil_tot, {'a', 'c', 'b'});
  if (results.size() != 0) {
    sort(results.begin(), results.end());
    for (auto &i : results) {
      cout << i.second.first << ' ' << i.second.second << ' ';
    }
    cout << endl;
    return;
  }
  results = result(pref_b, pref_a, pref_c, ceil_tot, {'b', 'a', 'c'});
  if (results.size() != 0) {
    sort(results.begin(), results.end());
    for (auto &i : results) {
      cout << i.second.first << ' ' << i.second.second << ' ';
    }
    cout << endl;
    return;
  }
  results = result(pref_b, pref_c, pref_a, ceil_tot, {'b', 'c', 'a'});
  if (results.size() != 0) {
    sort(results.begin(), results.end());
    for (auto &i : results) {
      cout << i.second.first << ' ' << i.second.second << ' ';
    }
    cout << endl;
    return;
  }
  results = result(pref_c, pref_a, pref_b, ceil_tot, {'c', 'a', 'b'});
  if (results.size() != 0) {
    sort(results.begin(), results.end());
    for (auto &i : results) {
      cout << i.second.first << ' ' << i.second.second << ' ';
    }
    cout << endl;
    return;
  }
  results = result(pref_c, pref_b, pref_a, ceil_tot, {'c', 'b', 'a'});
  if (results.size() != 0) {
    sort(results.begin(), results.end());
    for (auto &i : results) {
      cout << i.second.first << ' ' << i.second.second << ' ';
    }
    cout << endl;
    return;
  }

  cout << -1 << endl;
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
