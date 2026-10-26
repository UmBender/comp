#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
template <typename... T> void _dbg(const char *names, T &&...args) {
    cerr << "[" << names << "] =";
    ((cerr << ' ' << args), ...);
    cerr << endl;
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;

constexpr ll MOD = 1e9 + 7;

// Title: Linear sieve
// Description: Primes below n and the smallest prime factor of every x < n; factorization in O(log
// x). Usage:
//   Sieve sv(n);        // for [0, n)
//   sv.primes           // 2, 3, 5, ... < n
//   sv.spf[x]           // smallest prime factor of x (0 for x < 2)
//   sv.isPrime(x)       // 0 <= x < n
//   sv.factor(x)        // prime factors of 1 <= x < n, sorted, with multiplicity
// Complexity: O(n) build, O(log x) per factor.
// Verify: https://judge.yosupo.jp/problem/enumerate_primes
struct Sieve {
    vector<int> primes, spf;
    Sieve(int n) : spf(max(n, 0)) {
        for (int i = 2; i < n; i++) {
            if (!spf[i]) spf[i] = i, primes.push_back(i);
            for (int p : primes) { // i * p gets its smallest factor p exactly once
                if (p > spf[i] || (long long)i * p >= n) break;
                spf[i * p] = p;
            }
        }
    }
    bool isPrime(int x) const { return x >= 2 && spf[x] == x; }
    vector<int> factor(int x) const {
        vector<int> fs;
        for (; x > 1; x /= spf[x]) fs.push_back(spf[x]);
        return fs;
    }
};
// End: Linear sieve

Sieve sv(1e7);

ll phi(ll n) {
    ll acc = n;
    while (n > 1) {
        ll div = sv.spf[n];
        acc = (acc - acc / div);
        while (n % div == 0) { n /= div; }
    }
    return acc;
}

ll fastExp(ll base, ll exp) {
    ll acc = 1;
    while (exp) {
        if (exp & 1) {
            acc *= base;
            acc %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return acc;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll acc = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i) { continue; }
        ll temp = phi(n / i) * fastExp(m, i);
        temp %= MOD;
        acc += temp;
        temp %= MOD;
    }
    acc *= fastExp(n, MOD - 2);
    acc %= MOD;
    cout << acc << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
