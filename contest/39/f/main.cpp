#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }

using ll = long long;
#define int ll

vector<bool> sieve(30010);
vector<int> primes;

void set_sieve() {
  int num = 2;
  primes.push_back(2);
  for (int i = 2 * num; i < sieve.size(); i += num) {
    sieve[i] = true;
  }
  for (int i = 3; i < sieve.size(); i += 2) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i * 2; j < sieve.size(); j += i) {
        sieve[j] = true;
      }
    }
  }
}

vector<int>factors(int n) {
  vector<int> values;
  for(int p: primes) {
    while(n % p == 0) {
      values.push_back(p);
      n /=p;
    }
  }
  if(n != 1) {
    values.push_back(n);
  }
  return values;
}


void solution() {
  int k, n;
  cin >> k >> n;
  vector<int> facts = factors(n);



}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  set_sieve();

  int t;
  cin >> t;
  while (t--)
    solution();

  return 0;
}
