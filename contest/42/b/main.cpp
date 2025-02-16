// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  map<int, int> counter;
  for (int i = 0; i < a.size(); i++) {
    counter[a[i]]++;
  }

  bool finded_unique = false;

    for(auto i = counter.begin(); i != counter.end(); i++) {
    if(i->second ==1) {
      finded_unique = true;
      break;
    }
  }

  if(!finded_unique) {
    cout << 0 << endl;
    return;
  }

  int left = 0;
  int right = -1;
  int max_left = left;
  int max_right = right;
  int max_size = 0;
  queue<int> q;
  set<int> exists;
  for (int i = 0; i < n; i++) {
    if (counter[a[i]] == 1) {
      if (!exists.count(a[i])) {
        exists.insert(a[i]);
        q.push(a[i]);
        right++;
      } else {
        int head = q.front();
        q.pop();
        while (head != a[i]) {
          exists.erase(a[i]);
          left++;
          head = q.front();
          q.pop();
        }
        q.push(a[i]);
        right++;
      }
    } else {
      left = i + 1;
      right = i;
      exists.clear();
      while (!q.empty()) {
        q.pop();
      }
    }
    if (q.size() > max_size) {
      max_left = left;
      max_right = right;
      max_size = q.size();
    }
  }
  cout << max_left + 1 << ' ' << max_right + 1 << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
