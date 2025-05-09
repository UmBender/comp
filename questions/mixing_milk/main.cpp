// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
#include <cstdio>
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

void solution() {
    freopen("mixmilk.in", "r", stdin);
    int c[3], m[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lld %lld", &c[i], &m[i]);
    }
    for (int i = 0; i < 100; i++) {
        if (m[i % 3] + m[(i + 1) % 3] <= c[(i + 1) % 3]) {
            m[(i + 1) % 3] += m[i % 3];
            m[i % 3] = 0;
        } else {
            int diff = c[(i + 1) % 3] - m[(i + 1) % 3];
            m[i % 3] -= diff;
            m[(i + 1) % 3] = c[(i + 1) % 3];
        }
    }

    freopen("mixmilk.out", "w", stdout);
    for (int i = 0; i < 3; i++) {
        printf("%lld\n", m[i]);
    }
}

int32_t main() {
    // atcoder::modint::set_mod(998244353);
    solution();

    return 0;
}
