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

void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<pair<int, int>> acess;
  acess.push_back(make_pair(a[a.size() - 1], 1));
  for (int i = n - 2; i >= 0; i--) {
    if (acess.back().first / acess.back().second - a[i] <= 0) {
      acess.back().first += a[i];
      acess.back().second++;
      while ((acess[acess.size() - 2].first + acess[acess.size() - 2].second -
              1) / acess[acess.size() - 2].second -
                     (acess.back().first + acess.back().second - 1) /
                         acess.back().second <
                 0 &&
             acess.size() > 1) {
        acess[acess.size() - 2].first += acess.back().first;
        acess[acess.size() - 2].second += acess.back().second;
        acess.pop_back();
      }
    } else {
      acess.push_back(make_pair(a[i], 1));
    }
  }
  int minn = 0xffffff;
  int maxx = 0;
  for (auto &i : acess) {
    minn = min(i.first / i.second, minn);
    maxx = max(i.first / i.second + (i.first % i.second == 0 ? 0 : 1), maxx);
  }
  cout << maxx - minn << endl;
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
