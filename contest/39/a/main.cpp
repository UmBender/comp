#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

void solution() {
  int a1,a2,a4,a5;
  cin >> a1 >> a2 >> a4 >> a5;
  int left = a1 + a2;
  int middle = a4 - a2;
  int right = a5 - a4;
  if(left == middle  && middle == right) {
    cout << 3 << endl;
    return;
  }
  if(left == middle || left == right || middle == right) {
    cout << 2 << endl;
    return;
  }
  cout << 1 << endl;


  
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--)
    solution();

  return 0;
}
