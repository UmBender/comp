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

vector<bool> p(1E6);
vector<int>  primes;

void solution() {
    int n;
    cin >> n;
    vector<int>  p;
    int          counter      = 0;
    int          actual_prime = 0;
    int          acc          = 0;
    int          actual_pos   = 1;
    vector<bool> nums(n + 1);
    iota(nums.begin(), nums.end(), 0LL);

    bool pop = false;

    for (int i = 0; i < 100; i++) {
        if (!pop) {
            int value = primes[actual_prime] * (i + 1) - acc;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // atcoder::modint::set_mod(998244353);
    int inc = 1;

    for (int i = 2; i * i <= p.size(); i += inc) {
        if (p[i]) {
            continue;
        }
        for (int j = i + i; j <= p.size(); j += i) {
            p[j] = true;
        }
        if (i == 3) {
            inc += 2;
        }
    }
    for (int i = 2; i <= p.size(); i++) {
        if (!p[i]) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << primes[i] << endl;
    }
    return 0;
    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
