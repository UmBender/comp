// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <iterator>
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

vector<bool> sieve(1E6 + 100);
vector<int>  primes;

void set_primes() {

    for (int i = 4; i < sieve.size(); i += 2) {
        sieve[i] = true;
    }
    for (int i = 3; i * i < sieve.size(); i += 2) {
        if (!sieve[i]) {
            for (int j = i * i; j < sieve.size(); j += i) {
                sieve[j] = true;
            }
        }
    }
    for (int i = 2; i < sieve.size(); i++) {
        if (!sieve[i]) {
            primes.push_back(i);
        }
    }
}

map<int, int> factors(int n) {
    map<int, int> facs;
    int           actual = 0;
    while (n > 1 && actual < primes.size()) {
        while (n % primes[actual] == 0) {
            facs[primes[actual]]++;
            n /= primes[actual];
        }
        actual++;
    }
    if (n != 1) {
        facs[n]++;
    }
    return facs;
}

void solution() {
    int x, y, k;
    cin >> x >> y >> k;
    auto factorsx = factors(x);
    auto factorsy = factors(y);
    for (auto &[i, j] : factorsx) {
        if (factorsy.count(i)) {
            while (j > 0 && factorsy[i] > 0) {
                j--;
                factorsy[i]--;
            }
        }
    }
    bool is_possible = true;
    for (auto &[i, j] : factorsx) {
        if (j > 0) {
            if (i > k) {
                is_possible = false;
            }
        }
    }
    for (auto &[i, j] : factorsy) {
        if (j > 0) {
            if (i > k) {
                is_possible = false;
            }
        }
    }
    if (!is_possible) {
        cout << -1 << endl;
    } else {
        int div      = 0;
        int mult     = 0;
        int tilldiv  = 0;
        int tillmult = 0;
        int acc      = 1;
        for (auto &[i, j] : factorsx) {
            tilldiv += j;
        }
        for (auto &[i, j] : factorsy) {
            tillmult += j;
        }
        for (auto iter = factorsx.rbegin(); iter != factorsx.rend(); iter++) {
            while (iter->second > 0) {
                int actual = 1;
                for (auto niter = iter; niter != factorsx.rend(); niter++) {
                    while ((*niter).second != 0 && actual * niter->first < k) {
                        niter->second--;
                        actual *= niter->first;
                    }
                }
                if (actual != 1) {
                    div++;
                }
            }
        }
        for (auto iter = factorsy.rbegin(); iter != factorsy.rend(); iter++) {
            while (iter->second > 0) {
                int actual = 1;
                for (auto niter = iter; niter != factorsy.rend(); niter++) {
                    while (niter->second > 0 && actual * niter->first < k) {
                        niter->second--;
                        actual *= niter->first;
                    }
                }
                if (actual != 1) {
                    mult++;
                }
            }
        }
        cout << mult + div << endl;
    }
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
