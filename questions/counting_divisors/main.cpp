// #include <atcoder/all>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll

void sieve(int divisors[1000005]) {
  for (int i = 1; i < 1000005; i++) {
    for (int j = i; j < 1000005; j += i) {
      divisors[j]++;
    }
  }
}

void solution(int divisors[1000005]) {
  int n;
  cin >> n;
  cout << divisors[n] << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int divisors[1000005] = {};
  sieve(divisors);

  int t;
  cin >> t;
  while (t--)
    solution(divisors);

  return 0;
}
