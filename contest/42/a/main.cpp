// #include <atcoder/all>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void solution() {
  int n;
  cin >> n;
  string s, t;
  cin >> s;
  t = "";
  int counter = 0;
  int begin = n - 1;
  if (s.back() == '1') {
    counter++;
  }
  for (; begin >= 0 && s[begin] == '1'; begin--) {
  }
  char actual_letter = '0';
  for(int i = begin; i >= 0; i--) {
    if(actual_letter == '0' && s[i] == '1') {
      counter += 2;
      actual_letter = '1';
    }
    if(actual_letter == '1' && s[i] == '0') {
      actual_letter = '0';
    }
  }



  cout << counter << endl;
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
