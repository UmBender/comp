#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

bool make(vector<int> &first, vector<int> &second, int actual, int acc) {
  if (first[actual] + second[actual] >= acc + 2) {
    if (!second[actual]) {
      second[actual]++;
      first[actual] -= acc + 1;
    } else {
      first[actual] -= acc;
    }
    return true;
  }

  if (actual == 1) {
    return false;
  }
  int diff = (acc + 2) - (first[actual] + second[actual]);
  bool got = make(first, second, actual - 1, diff);
  if (got) {
    first[actual] = 1;
    second[actual] = 1;
    return true;

  } else {
    return false;
  }
}

void solution() {

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> first(n + 1);
  vector<int> second(n + 1);
  for (auto &i : a) {
    cin >> i;
    first[i]++;
  }
  sort(a.rbegin(), a.rend());
  for (int i = first.size() - 1; i > 0; i--) {
    if (first[i] != second[i]) {
      if ((first[i] + second[i]) % 2 == 0) {
        first[i]/=2;
        second[i] = first[i];
      }else{
        if(make(first, second, i-1, 1)) {
          first[i]++;
          first[i]/= 2;
          second[i] = first[i]; 
        }else{
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
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
