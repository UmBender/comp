#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
using mint = atcoder::modint;

void solution() {
  string input;
  cin >> input;
  int mes = (input[5] - '0') * 10 + (input[6] - '0');
  int dia = (input[8] - '0') * 10 + (input[9] - '0');
  if (mes < 9) {
    cout << "GOOD" << endl;
    return;
  }
  if (mes == 9 && dia <= 16) {
    cout << "GOOD" << endl;
    return;
  }
  cout << "TOO LATE" << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  atcoder::modint::set_mod(998244353);
  solution();

  return 0;
}
