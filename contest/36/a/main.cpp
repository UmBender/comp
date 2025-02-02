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
  vector<int> b(n);
  set<int> an;
  int diffa = 0;
  int diffb = 0;
  set<int> bn;
  for (auto &i : a) {
    cin >> i;
    if (!an.count(i)) {
      an.insert(i);
      diffa++;
    }
  }
  for (auto &i : b) {
    cin >> i;
    if (!bn.count(i)) {
      bn.insert(i);
      diffb++;
    }
  }
  if (diffa == 1 || diffb == 1) {
    if (diffb >= 3) {
      cout << "YES" << endl;
      return;
    }
    if (diffa >= 3) {
      cout << "YES" << endl;
      return;
    }

    cout << "NO" << endl;
    return;
  }
  if (diffa == 2 || diffb == 2) {
    if (diffa == 1) {
      cout << "NO" << endl;
      return;
    }
    if (diffb == 1) {
      cout << "NO" << endl;
      return;
    }

    if (diffa >= 3) {
      cout << "YES" << endl;
      return;
    }
    if (diffb >= 3) {
      cout << "YES" << endl;
      return;
    }

    if (diffa == 2 && diffb == 2) {
      if (n == 3) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {

    solution();
  }

  return 0;
}
