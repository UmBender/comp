// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void __dbg() { cerr << endl; }
template <typename T> void __dbg(T t) { cerr << t << endl; }
template <typename T, typename... TRest> void __dbg(T first, TRest... rest) {
  cerr << first << ", ";
  __dbg(rest...);
}
#define dbg(...)                                                               \
  do {                                                                         \
    cerr << "DBG> " << "(" << #__VA_ARGS__ << ") = ";                          \
    __dbg(__VA_ARGS__);                                                        \
  } while (0)
#define MAX_INT ((int64_t)1E18 + 1000)
#define makefn(fn) [](auto... args) { return fn(args...); }
using ll = long long;
#define int ll
//using mint = atcoder::modint;
// clang-format on

vector<bool> sieve(1E7 + 10);
vector<int>  primes;
void         set_primes() {
    for (int i = 4; i < sieve.size(); i += 2) {
        sieve[i] = true;
    }
    for (int i = 3; i < sieve.size(); i += 2) {
        if (sieve[i]) {
            continue;
        }
        for (int j = i + i; j < sieve.size(); j+=i) {
            sieve[j] = true;
        }
    }
    for (int i = 2; i < sieve.size(); i++) {
        if (!sieve[i]) {
            primes.push_back(i);
        }
    }
}

int bs(int right_max, int target, int a) {
    int l = 0;
    int r = min(right_max, (int)primes.size());
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a * primes[m] <= target && a * primes[m + 1] > target) {
            return m;
        }
        if (a * primes[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return r;
}
void solution() {
    int n;
    cin >> n;
    int counter   = 0;
    int right_max = primes.size();

    for (int i = 1; i < n; i++) {
        int pos = bs(right_max, n, i);
        counter += pos + 1;
        right_max = pos;
    }
    cout << counter << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    set_primes();
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
