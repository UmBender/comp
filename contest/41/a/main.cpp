#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

void solution() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  vector<int> sizes(n);
  for (auto &i : s) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    sizes[i] = s[i].size();
  }

  int acc =0;
  int actual_size =0;
  for(int i = 0; i < n; i++) {
    if(acc + sizes[i] <= m) {
      acc+= sizes[i];
      actual_size++;
    }else{
      break;
    }
  }
  cout << actual_size << endl;
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
