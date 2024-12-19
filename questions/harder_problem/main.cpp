#include <bits/stdc++.h>

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

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &i : a) {
    cin >> i;
  }
  set<int> numbers;
  set<int> used;
  set<int> not_used;
  for (int i : a) {
    if (!numbers.count(i)) {
      numbers.insert(i);
      not_used.insert(i);
    }
  }

  for (int i = 0; i < n; i++) {
    int inserted_element;

    if (used.count(a[i]) == 1) {
      inserted_element = *not_used.begin();
    } else {
      inserted_element = a[i];
    }

    used.insert(inserted_element);
    not_used.erase(inserted_element);
    b[i] = inserted_element;

    if (not_used.size() == 0) {
      for (auto i : numbers) {
        not_used.insert(i);
      }
      used.clear();
    }
  }
  for (auto i : b) {
    cout << i << ' ';
  }
  cout << endl;
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
