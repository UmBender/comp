#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    int best = s[i] - '0';
    int max_pos = i;
    for (int j = i + 1; j < s.size() && j < i + 10; j++) {
      if (best < s[j] - '0' - (j - i)) {
        max_pos = j;
        best = s[j] - '0' - (j - i);
      }
    }
    while (max_pos > i) {
      swap(s[max_pos], s[max_pos - 1]);
      max_pos--;
    }
    s[i] = (char)best + '0';
  }
  cout << s << endl;
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
