#include <bits/stdc++.h>
#include <cstdlib>
#include <utility>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;

void solution() {
  ll n, m, k;
  cin >> n >> m >> k;
  if (abs(n - m) > k) {
    cout << -1 << endl;
    return;
  }
  if(max(n,m) < k) {
    cout << -1 << endl;
    return;
  }
  pair<ll, char> high, low;
  if (n > m) {
    high = make_pair(n, '0');
    low = make_pair(m, '1');
  } else {
    high = make_pair(m, '1');
    low = make_pair(n, '0');
  }
  vector<char> result;
  for (ll i = 0; i < k; i++) {
    result.push_back(high.second);
    high.first--;
  }
  swap(high, low);
  while (high.first > 0) {
    result.push_back(high.second);
    high.first--;
    swap(high, low);
  }
  swap(high, low);
  while (high.first>0) {
    result.push_back(high.second);
    high.first--;
  }
  for(char i: result) {
    cout << i;
  }
  cout << endl;
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
